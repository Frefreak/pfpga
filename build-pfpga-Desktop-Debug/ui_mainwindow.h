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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *sopcLabel;
    QLineEdit *sopcLineEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(504, 469);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 40, 481, 161));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayoutWidget = new QWidget(frame);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(30, 20, 381, 33));
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

        formLayout->setWidget(0, QFormLayout::FieldRole, sofLineEdit);

        formLayoutWidget_2 = new QWidget(frame);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(30, 60, 381, 33));
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

        formLayout_2->setWidget(0, QFormLayout::FieldRole, elfLineEdit);

        sofButton = new QToolButton(frame);
        sofButton->setObjectName(QStringLiteral("sofButton"));
        sofButton->setGeometry(QRect(430, 20, 31, 31));
        elfButton = new QToolButton(frame);
        elfButton->setObjectName(QStringLiteral("elfButton"));
        elfButton->setGeometry(QRect(430, 60, 31, 31));
        sopcButton = new QToolButton(frame);
        sopcButton->setObjectName(QStringLiteral("sopcButton"));
        sopcButton->setGeometry(QRect(430, 100, 31, 31));
        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 100, 381, 33));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sopcLabel = new QLabel(widget);
        sopcLabel->setObjectName(QStringLiteral("sopcLabel"));

        horizontalLayout->addWidget(sopcLabel);

        sopcLineEdit = new QLineEdit(widget);
        sopcLineEdit->setObjectName(QStringLiteral("sopcLineEdit"));

        horizontalLayout->addWidget(sopcLineEdit);

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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
