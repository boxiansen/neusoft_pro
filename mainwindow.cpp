#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);
    //connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayError(QAbstractSocket::SocketError)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newConnect()
{

    tcpSocket->abort();
    tcpSocket->connectToHost(ui->hostLineEdit->text(),ui->portLineEdit->text().toInt());
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));

}
void MainWindow::readMessage()
{
    //获取当前时间
        current_date_time = QDateTime::currentDateTime();
        str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss")+"\n";

     QString str = tcpSocket->readAll();

     str = "Server "+str_date_time+str;
     this->ui->reading_message->append(str);


}
void MainWindow::displayError(QAbstractSocket::SocketError)
{

    qDebug() << tcpSocket->errorString(); //输出错误信息
}
void MainWindow::on_pushButton_clicked()
{
     newConnect(); //请求连接dasdasdsa
}

void MainWindow::on_send_message_pushbutton_clicked()
{
    QString str = ui->sending_message->text();

    //this->tcpSocket->write(ui->sending_message->text().toLatin1());
    this->tcpSocket->write(ui->sending_message->text().toUtf8());
    //显示
        current_date_time = QDateTime::currentDateTime();
        str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
        str = "You "+str_date_time+"\n"+str;
        ui->reading_message->append(str);
}
