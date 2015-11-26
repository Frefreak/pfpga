#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QSettings>
#include <QDebug>
#include <QFileDialog>
#include <QScrollBar>
#include <QXmlStreamReader>
#include <QMessageBox>
//#include <KDE/KPtyProcess>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadFilePath();
    process = new QProcess();
    process->setProcessChannelMode(QProcess::MergedChannels);
    QObject::connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(appendStdoutText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::loadFilePath()
{
    QSettings *setting = new QSettings(ORG, qApp->applicationName());
    setting->beginGroup("FilePath");
    selected_sof = setting->value(SOF, "").toString();
    selected_elf = setting->value(ELF, "").toString();
    selected_sopc = setting->value(SOPC, "").toString();
    ui->sofLineEdit->setText(selected_sof);
    ui->elfLineEdit->setText(selected_elf);
    ui->sopcLineEdit->setText(selected_sopc);
    setting->endGroup();
}

void MainWindow::saveFilePath(QString key, QString value)
{
    QSettings *setting = new QSettings(ORG, qApp->applicationName());
    setting->beginGroup("FilePath");
    setting->setValue(key, value);
    setting->endGroup();
}

void MainWindow::saveCurrentDir(QString value)
{
    QDir dir = QFileInfo(value).absoluteDir();
    QSettings *setting = new QSettings(ORG, qApp->applicationName());
    setting->beginGroup("CurrentDirectory");
    setting->setValue(curDir, dir.absolutePath());
    setting->endGroup();
}

QString MainWindow::getCurrentDir()
{
    QSettings *setting = new QSettings(ORG, qApp->applicationName());
    setting->beginGroup("CurrentDirectory");
    QString cur = setting->value(curDir).toString();
    setting->endGroup();
    return  cur;
}

void MainWindow::on_sofButton_clicked()
{
    QString path = getCurrentDir();
    path = QFileDialog::getOpenFileName(NULL, "Open SOF File",
                                                path, "sof file (*.sof)");
    if (!path.isEmpty())
        if (path.right(4) == ".sof") {
            ui->sofLineEdit->setText(path);
            saveFilePath(SOF, path);
            saveCurrentDir(path);
            selected_sof = path;
        }
}

void MainWindow::on_elfButton_clicked()
{
    QString path = getCurrentDir();
    path = QFileDialog::getOpenFileName(NULL, "Open ELF File",
                                                path, "elf file (*.elf)");
    if (!path.isEmpty())
        if (path.right(4) == ".elf") {
            ui->elfLineEdit->setText(path);
            saveFilePath(ELF, path);
            saveCurrentDir(path);
            selected_elf = path;
        }
}

void MainWindow::on_sopcButton_clicked()
{
    QString path = getCurrentDir();
    path = QFileDialog::getOpenFileName(NULL, "Open SOPC File",
                                                path, "sopc file (*.sopcinfo)");
    if (!path.isEmpty())
        if (path.right(9) == ".sopcinfo") {
            ui->sopcLineEdit->setText(path);
            saveFilePath(SOPC, path);
            saveCurrentDir(path);
            selected_sopc = path;
        }
}


void MainWindow::insertTextHelper(QString s)
{
    QPlainTextEdit *widget = ui->stdout;
    const QTextCursor old_cursor = widget->textCursor();
    const int old_scrollbar_value = widget->verticalScrollBar()->value();
    const bool is_scrolled_down = old_scrollbar_value == widget->verticalScrollBar()->maximum();

    widget->moveCursor(QTextCursor::End);
    widget->textCursor().insertText(s);
    widget->setTextCursor(old_cursor);

    if (!is_scrolled_down)
        widget->verticalScrollBar()->setValue(old_scrollbar_value);
    else
        widget->verticalScrollBar()->setValue(widget->verticalScrollBar()->maximum());

}

void MainWindow::appendStdoutText()
{
    insertTextHelper(QString(process->readAllStandardOutput()));
}

bool MainWindow::parseSOPC()
{
    getSysInfo();
    if (sysid.isEmpty() ||
            sysid_base.isEmpty() ||
            timestamp.isEmpty())
        return false;
    return true;
}

/* Scan file. Get System id name, System id and timestamp */
void MainWindow::getSysInfo()
{
    QSettings *setting = new QSettings(ORG, qApp->applicationName());
    setting->beginGroup("FilePath");
    QFile sopcFile(setting->value(SOPC).toString());
    sopcFile.open(QIODevice::ReadOnly);
    QXmlStreamReader reader(&sopcFile);
    setting->endGroup();

    QString cdata;
    QString sysid_name;
    reader.readNext();
    while (!reader.isEndDocument()) {
        if (reader.isStartElement())
            if (reader.name() == "module") {
                if (reader.attributes().value("kind") == SYSID) {
                    sysid_name = reader.attributes().value("name").toString();
                    QString temp;
                    int flag = 0;
run_twice:          do {
                        reader.readNext();
                        temp = reader.name().toString();
                    }  while (temp != "name" && flag != 2);
                    temp =  reader.readElementText();
                    if (temp == ID) {
                        do
                            reader.readNext();
                        while (reader.name() != "value");
                        sysid = reader.readElementText();
                        flag++;
                        goto run_twice;
                    } else if (temp == TIMESTAMP) {
                        do
                            reader.readNext();
                        while (reader.name() != "value");
                        timestamp = reader.readElementText();
                        flag++;
                        goto run_twice;
                    }
                } else if (reader.attributes().value("kind") == NIOS2) {
                    do
                        reader.readNext();
                    while (reader.attributes().value("name") != NIOS2_DATAMASTER);
                    do
                        reader.readNext();
                    while (!reader.isCDATA());
                    cdata =  reader.text().toString();
                }
            } else if (reader.name() == "EnsembleReport") {
                ;	// don't skip top level element
            } else
                reader.skipCurrentElement();	// skip unrelevent elements
        reader.readNext();
    }

    sysid.setNum(sysid.toUInt(NULL, 10), 16);
    sysid = "0x" + sysid;
    sopcFile.close();

    /* Scan CDATA. Get sysid base addr */
    reader.clear();
    reader.addData(cdata);

    while (!reader.isEndDocument()) {
        if (reader.name() == "slave" && reader.attributes().value("name") == sysid_name + ".control_slave") {
            sysid_base = reader.attributes().value("start").toString();
            break;
        }
        reader.readNext();
    }
}

void MainWindow::alert(QString s)
{
    QMessageBox messageBox;
    messageBox.critical(0,"Error",s);
    messageBox.setFixedSize(500,200);
}

void MainWindow::on_program_fpga_clicked()
{
    if (selected_sof.isEmpty())
        alert("You must choose an sof file to program your FPGA! ");
    process->start(SCRIPT, QStringList() << "1" << selected_sof);
}

void MainWindow::on_flash_fpga_clicked()
{
    if (selected_sof.isEmpty())
        alert("You must choose an sof file to flash your FPGA! ");
    process->start(SCRIPT, QStringList() << "2" << selected_sof);
}

void MainWindow::on_program_nios_clicked()
{
    if (parseSOPC())
        process->start(SCRIPT, QStringList() << "3" << selected_sof
                       << selected_elf << sysid << sysid_base << timestamp);
    else
        alert("Invalid SOPC info file! ");

}

void MainWindow::on_flash_nios_clicked()
{
    if (parseSOPC())
        process->start(SCRIPT, QStringList() << "4" << selected_sof
                       << selected_elf << sysid << sysid_base << timestamp);
    else
        alert("Invalid SOPC info file! ");

}

void MainWindow::on_clearButton_clicked()
{
    ui->stdout->clear();
}
