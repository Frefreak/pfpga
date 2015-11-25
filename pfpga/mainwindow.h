#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sofButton_clicked();

    void on_elfButton_clicked();

    void on_sopcButton_clicked();

private:
    Ui::MainWindow *ui;
    void loadFilePath();
    void saveFilePath(QString key, QString value);
    QString getCurrentDir();
    void saveCurrentDir(QString value);

};

#define SOF "sof_file_path"
#define ELF "elf_file_path"
#define SOPC "sopc_file_path"
#define curDir "currentDirectory"

#define ORG "adv_zxy"

#endif // MAINWINDOW_H
