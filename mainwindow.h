#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QString message;  //存放从服务器接收到的字符串
    quint16 blockSize; //存放文件的大小信息
    //系统时间
        QDateTime current_date_time;
        QString str_date_time;


private slots:

void newConnect(); //连接服务器
void readMessage();  //接收数据
void displayError(QAbstractSocket::SocketError);  //显示错误
void on_pushButton_clicked();
void on_send_message_pushbutton_clicked();
};

#endif // MAINWINDOW_H
