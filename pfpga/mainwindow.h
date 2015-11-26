#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString sysid;
    QString sysid_base;
    QString timestamp;

private slots:
    void on_sofButton_clicked();

    void on_elfButton_clicked();

    void on_sopcButton_clicked();

    void appendStdoutText();

    void on_program_fpga_clicked();

    void on_flash_fpga_clicked();

    void on_program_nios_clicked();

    void on_flash_nios_clicked();

private:
    Ui::MainWindow *ui;
    void loadFilePath();
    void saveFilePath(QString key, QString value);
    QString getCurrentDir();
    void saveCurrentDir(QString value);
    void insertTextHelper(QString s);
    void getSysInfo();
    bool parseSOPC();

    QProcess *process;

    QString selected_sof;
    QString selected_elf;
    QString selected_sopc;
};

#define SOF "sof_file_path"
#define ELF "elf_file_path"
#define SOPC "sopc_file_path"
#define curDir "currentDirectory"

#define SYSID "altera_avalon_sysid_qsys"
#define NIOS2 "altera_nios2_qsys"
#define NIOS2_DATAMASTER "dataSlaveMapParam"
#define ID "embeddedsw.CMacro.ID"
#define TIMESTAMP "embeddedsw.CMacro.TIMESTAMP"
#define ORG "."

#endif // MAINWINDOW_H
