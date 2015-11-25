#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QSettings>
#include <QDebug>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadFilePath();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::loadFilePath()
{
    QSettings *setting = new QSettings(ORG, qApp->applicationName());
    setting->beginGroup("FilePath");
    ui->sofLineEdit->setText(setting->value(SOF, "").toString());
    ui->elfLineEdit->setText(setting->value(ELF, "").toString());
    ui->sopcLineEdit->setText(setting->value(SOPC, "").toString());
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
                                                path, "sof files (*.sof)");
    if (!path.isEmpty())
        if (path.right(4) == ".sof") {
            ui->sofLineEdit->setText(path);
            saveFilePath(SOF, path);
            saveCurrentDir(path);
        }
}

void MainWindow::on_elfButton_clicked()
{
    QString path = getCurrentDir();
    path = QFileDialog::getOpenFileName(NULL, "Open ELF File",
                                                path, "elf files (*.elf)");
    if (!path.isEmpty())
        if (path.right(4) == ".elf") {
            ui->elfLineEdit->setText(path);
            saveFilePath(ELF, path);
            saveCurrentDir(path);
        }
}

void MainWindow::on_sopcButton_clicked()
{
    QString path = getCurrentDir();
    path = QFileDialog::getOpenFileName(NULL, "Open SOPC File",
                                                path, "sopc files (*.sopcinfo)");
    if (!path.isEmpty())
        if (path.right(5) == ".sopc") {
            ui->sopcLineEdit->setText(path);
            saveFilePath(SOPC, path);
            saveCurrentDir(path);
        }
}
