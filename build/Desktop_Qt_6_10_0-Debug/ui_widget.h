/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QRadioButton *rbTcp;
    QRadioButton *rbSsl;
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

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(386, 600);
        rbTcp = new QRadioButton(Widget);
        rbTcp->setObjectName("rbTcp");
        rbTcp->setGeometry(QRect(270, 30, 109, 24));
        rbTcp->setChecked(true);
        rbSsl = new QRadioButton(Widget);
        rbSsl->setObjectName("rbSsl");
        rbSsl->setGeometry(QRect(270, 70, 109, 24));
        rbSsl->setAutoFillBackground(false);
        rbSsl->setChecked(false);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 30, 258, 488));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pbConnect = new QPushButton(widget);
        pbConnect->setObjectName("pbConnect");

        gridLayout->addWidget(pbConnect, 0, 0, 1, 1);

        pbDisconnect = new QPushButton(widget);
        pbDisconnect->setObjectName("pbDisconnect");
        pbDisconnect->setEnabled(false);

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

        gridLayout->addWidget(pbSend, 4, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        rbTcp->setText(QCoreApplication::translate("Widget", "tcpSocket", nullptr));
        rbSsl->setText(QCoreApplication::translate("Widget", "sslSocket", nullptr));
        pbConnect->setText(QCoreApplication::translate("Widget", "Connect", nullptr));
        pbDisconnect->setText(QCoreApplication::translate("Widget", "Disconnect", nullptr));
        pbClear->setText(QCoreApplication::translate("Widget", "Clear", nullptr));
        leHost->setText(QCoreApplication::translate("Widget", "www.naver.com", nullptr));
        lePort->setText(QCoreApplication::translate("Widget", "443", nullptr));
        pteSend->setPlainText(QCoreApplication::translate("Widget", "GET / HTTP/1.1\n"
"HOST:www.naver.com\n"
"\n"
"", nullptr));
        pbSend->setText(QCoreApplication::translate("Widget", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
