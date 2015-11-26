/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *sofLabel;
    QLineEdit *sofLineEdit;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *elfLabel;
    QLineEdit *elfLineEdit;
    QToolButton *sofButton;
    QToolButton *elfButton;
    QToolButton *sopcButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *sopcLabel;
    QLineEdit *sopcLineEdit;
    QPlainTextEdit *stdout;
    QGroupBox *groupBox_3;
    QPushButton *flash_nios;
    QPushButton *program_nios;
    QGroupBox *groupBox_2;
    QPushButton *program_fpga;
    QPushButton *flash_fpga;
    QPushButton *clearButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(636, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 10, 591, 161));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayoutWidget = new QWidget(frame);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 20, 481, 33));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        sofLabel = new QLabel(formLayoutWidget);
        sofLabel->setObjectName(QStringLiteral("sofLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, sofLabel);

        sofLineEdit = new QLineEdit(formLayoutWidget);
        sofLineEdit->setObjectName(QStringLiteral("sofLineEdit"));
        sofLineEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, sofLineEdit);

        formLayoutWidget_2 = new QWidget(frame);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(30, 60, 481, 33));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        elfLabel = new QLabel(formLayoutWidget_2);
        elfLabel->setObjectName(QStringLiteral("elfLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, elfLabel);

        elfLineEdit = new QLineEdit(formLayoutWidget_2);
        elfLineEdit->setObjectName(QStringLiteral("elfLineEdit"));
        elfLineEdit->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, elfLineEdit);

        sofButton = new QToolButton(frame);
        sofButton->setObjectName(QStringLiteral("sofButton"));
        sofButton->setGeometry(QRect(530, 20, 31, 31));
        elfButton = new QToolButton(frame);
        elfButton->setObjectName(QStringLiteral("elfButton"));
        elfButton->setGeometry(QRect(530, 60, 31, 31));
        sopcButton = new QToolButton(frame);
        sopcButton->setObjectName(QStringLiteral("sopcButton"));
        sopcButton->setGeometry(QRect(530, 100, 31, 31));
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 100, 481, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sopcLabel = new QLabel(layoutWidget);
        sopcLabel->setObjectName(QStringLiteral("sopcLabel"));

        horizontalLayout->addWidget(sopcLabel);

        sopcLineEdit = new QLineEdit(layoutWidget);
        sopcLineEdit->setObjectName(QStringLiteral("sopcLineEdit"));
        sopcLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(sopcLineEdit);

        stdout = new QPlainTextEdit(centralWidget);
        stdout->setObjectName(QStringLiteral("stdout"));
        stdout->setGeometry(QRect(20, 180, 592, 262));
        stdout->setMinimumSize(QSize(80, 0));
        QFont font;
        font.setFamily(QStringLiteral("Fantasque Sans Mono"));
        stdout->setFont(font);
        stdout->setReadOnly(true);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(370, 450, 200, 125));
        flash_nios = new QPushButton(groupBox_3);
        flash_nios->setObjectName(QStringLiteral("flash_nios"));
        flash_nios->setGeometry(QRect(50, 70, 100, 35));
        program_nios = new QPushButton(groupBox_3);
        program_nios->setObjectName(QStringLiteral("program_nios"));
        program_nios->setGeometry(QRect(50, 30, 100, 35));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(60, 450, 200, 125));
        program_fpga = new QPushButton(groupBox_2);
        program_fpga->setObjectName(QStringLiteral("program_fpga"));
        program_fpga->setGeometry(QRect(50, 30, 100, 35));
        flash_fpga = new QPushButton(groupBox_2);
        flash_fpga->setObjectName(QStringLiteral("flash_fpga"));
        flash_fpga->setGeometry(QRect(50, 70, 100, 35));
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(270, 500, 90, 32));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        sofLabel->setText(QApplication::translate("MainWindow", "sof:", 0));
        elfLabel->setText(QApplication::translate("MainWindow", "elf:", 0));
        sofButton->setText(QApplication::translate("MainWindow", "...", 0));
        elfButton->setText(QApplication::translate("MainWindow", "...", 0));
        sopcButton->setText(QApplication::translate("MainWindow", "...", 0));
        sopcLabel->setText(QApplication::translate("MainWindow", "sopc:", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "ELF", 0));
        flash_nios->setText(QApplication::translate("MainWindow", "Flash", 0));
        program_nios->setText(QApplication::translate("MainWindow", "Program", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "SOF", 0));
        program_fpga->setText(QApplication::translate("MainWindow", "Program", 0));
        flash_fpga->setText(QApplication::translate("MainWindow", "Flash", 0));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
