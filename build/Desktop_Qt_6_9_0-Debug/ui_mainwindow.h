/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *pbConnect;
    QPushButton *pbDisconnect;
    QPushButton *pbClear;
    QLineEdit *leHost;
    QLineEdit *lePort;
    QPlainTextEdit *pteSend;
    QPlainTextEdit *pteMessage;
    QPushButton *pbSend;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(454, 488);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(61, 44, 344, 456));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pbConnect = new QPushButton(widget);
        pbConnect->setObjectName("pbConnect");

        gridLayout->addWidget(pbConnect, 0, 0, 1, 1);

        pbDisconnect = new QPushButton(widget);
        pbDisconnect->setObjectName("pbDisconnect");

        gridLayout->addWidget(pbDisconnect, 0, 1, 1, 2);

        pbClear = new QPushButton(widget);
        pbClear->setObjectName("pbClear");

        gridLayout->addWidget(pbClear, 0, 3, 1, 1);

        leHost = new QLineEdit(widget);
        leHost->setObjectName("leHost");

        gridLayout->addWidget(leHost, 1, 0, 1, 2);

        lePort = new QLineEdit(widget);
        lePort->setObjectName("lePort");

        gridLayout->addWidget(lePort, 1, 2, 1, 2);

        pteSend = new QPlainTextEdit(widget);
        pteSend->setObjectName("pteSend");

        gridLayout->addWidget(pteSend, 2, 0, 1, 4);

        pteMessage = new QPlainTextEdit(widget);
        pteMessage->setObjectName("pteMessage");

        gridLayout->addWidget(pteMessage, 3, 0, 1, 4);

        pbSend = new QPushButton(widget);
        pbSend->setObjectName("pbSend");

        gridLayout->addWidget(pbSend, 3, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 454, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pbConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pbDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        pbClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        leHost->setText(QCoreApplication::translate("MainWindow", "naver.com", nullptr));
        lePort->setText(QCoreApplication::translate("MainWindow", "80", nullptr));
        pteSend->setPlainText(QCoreApplication::translate("MainWindow", "GET / HTTP/1.1\n"
"Host : naver.com \n"
"\n"
"", nullptr));
        pbSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
