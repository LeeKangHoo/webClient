#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //socket_.connected
    QObject::connect(&socket_, &QAbstractSocket::connected, this, &MainWindow::doConnected);
    QObject::connect(&socket_, &QAbstractSocket::disconnected, this, &MainWindow::doDisconnected);
    QObject::connect(&socket_, &QIODevice::readyRead, this, &MainWindow::doReadyRead);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::doConnected(){
    QString msg = "connected\r\n";
    ui->pteMessage->insertPlainText(msg);

}

void MainWindow::doDisconnected(){
    QString msg = "disconnected\r\n";
    ui->pteMessage->insertPlainText(msg);

}
void MainWindow::doReadyRead(){
    QString msg = socket_.readAll();
    ui->pteMessage->insertPlainText(msg);
}

void MainWindow::on_pbConnect_clicked()
{
    socket_.connectToHost(ui->leHost->text(),ui->lePort->text().toUShort());
    //socket_.connectToHostEncrypted(ui->leHost->text(),ui->leHost->text().toUShort());
}


void MainWindow::on_pbDisconnect_clicked()
{
    socket_.disconnectFromHost();
}


void MainWindow::on_pbSend_clicked()
{
    socket_.write(ui->pteSend->toPlainText().toUtf8());
}

