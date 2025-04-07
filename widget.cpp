#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    loadState();

    //tcpSocket
    QObject::connect(&socket_tcp, &QAbstractSocket::connected, this, &Widget::doConnected);
    QObject::connect(&socket_tcp, &QAbstractSocket::disconnected, this, &Widget::doDisconnected);
    QObject::connect(&socket_tcp, &QIODevice::readyRead, this, &Widget::doReadyRead);
    //sslSocket
    QObject::connect(&socket_ssl, &QAbstractSocket::connected, this, &Widget::doConnected);
    QObject::connect(&socket_ssl, &QAbstractSocket::disconnected, this, &Widget::doDisconnected);
    QObject::connect(&socket_ssl, &QIODevice::readyRead, this, &Widget::doReadyRead);

    //state check
    QObject::connect(&socket_tcp,&QAbstractSocket::stateChanged,this,&Widget::changeState);
    QObject::connect(&socket_ssl,&QAbstractSocket::stateChanged,this,&Widget::changeState);

    changeState();

}

Widget::~Widget()
{
    saveState();
    delete ui;
}

void Widget::saveState()
{
    QSettings settings("sdev3","nine9");

    settings.setValue("window/pos",pos());

    settings.setValue("le/host",ui->leHost->text());
    settings.setValue("le/port",ui->lePort->text());

    settings.setValue("pte/send",ui->pteSend->toPlainText());
    settings.setValue("pte/message",ui->pteMessage->toPlainText());


}

void Widget::loadState()
{
    QSettings settings("sdev3","nine9");

    QPoint pos = settings.value("window/pos",QPoint(200,200)).toPoint();
    move(pos);

    QString leh = settings.value("le/host","www.naver.com").toString();
    QString lep = settings.value("le/port","80").toString();
    ui->leHost->setText(leh);
    ui->lePort->setText(lep);

    QString ptes = settings.value("pte/send","GET / HTTP/1.1\r\nHost:www.naver.com\r\n").toString();
    QString ptem = settings.value("pte/message","").toString();
    ui->pteSend->setPlainText(ptes);
    ui->pteMessage->setPlainText(ptem);


}


void Widget::changeState()
{
    if (socket_tcp.state()== 3 || socket_ssl.state() == 3)
    {
        ui->pbDisconnect->setEnabled(true);
        ui->pbConnect->setEnabled(false);
        ui->pbSend->setEnabled(true);
    }
    else
    {
        ui->pbDisconnect->setEnabled(false);
        ui->pbConnect->setEnabled(true);
        ui->pbSend->setEnabled(false);
    }
}

void Widget::doConnected()
{
    QString msg = "connected\r\n";
    ui->pteMessage->insertPlainText(msg);
    changeState();

}

void Widget::doDisconnected()
{
    QString msg = "disconnected\r\n";
    ui->pteMessage->insertPlainText(msg);
    changeState();
}

void Widget::doReadyRead()
{
    if (ui->rbTcp->isChecked())
    {
        QString msg = socket_tcp.readAll();
        ui->pteMessage->insertPlainText(msg);
    }
    else
    {
        QString msg = socket_ssl.readAll();
        ui->pteMessage->insertPlainText(msg);
    }
}


void Widget::on_pbConnect_clicked()
{
    if (ui->rbTcp->isChecked())
    {
        socket_tcp.connectToHost(ui->leHost->text(),ui->lePort->text().toUShort());
    }
    else
    {
        socket_ssl.connectToHostEncrypted(ui->leHost->text(),ui->lePort->text().toUShort());
    }

}


void Widget::on_pbDisconnect_clicked()
{
    if (ui->rbTcp->isChecked())
    {
        socket_tcp.disconnectFromHost();
    }
    else
    {
        socket_ssl.disconnectFromHost();
    }
}


void Widget::on_pbClear_clicked()
{
    ui->pteMessage->setPlainText("");
}


void Widget::on_pbSend_clicked()
{
    if (ui->rbTcp->isChecked())
    {
        socket_tcp.write(ui->pteSend->toPlainText().toUtf8());
    }
    else
    {
        socket_ssl.write(ui->pteSend->toPlainText().toUtf8());
    }

}

