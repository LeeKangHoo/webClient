#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QSslSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTcpSocket socket_;
    //QSslSocket socket_;

public slots:
    void doConnected();
    void doDisconnected();
    void doReadyRead();

private slots:
    void on_pbConnect_clicked();

    void on_pbDisconnect_clicked();

    void on_pbSend_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
