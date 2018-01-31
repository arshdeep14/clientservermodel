#include "server.h"

Server::Server(QWidget *parent) : QMainWindow(parent)
{
    QWidget *swindow=new QWidget;
    sserver=new QTcpServer(this);
    start=new QPushButton("Start");
    stop=new QPushButton("Stop");
    status=new QLabel("Status");
    status2=new QLabel("");
    connected=new QLabel("Connected");
    inbox=new QLabel("Chat");
    message=new QLabel("Message");
    send=new QPushButton("Send");
    connectedp=new QLineEdit;
    inboxm=new QTextEdit;
    messaget=new QLineEdit;
    QHBoxLayout *layout1=new QHBoxLayout;
    layout1->addWidget(start);
    layout1->addWidget(stop);
     QHBoxLayout *layout2=new QHBoxLayout;
     layout2->addWidget(status);
     layout2->addWidget(status2);

     QHBoxLayout *layout3=new QHBoxLayout;
     layout3->addWidget(connected);
     layout3->addWidget(inbox);
     QHBoxLayout *layout4=new QHBoxLayout;
     layout4->addWidget(connectedp);
     layout4->addWidget(inboxm);
     QHBoxLayout *layout5=new QHBoxLayout;
     layout5->addWidget(message);
     layout5->addWidget(messaget);
     QHBoxLayout *layout6=new QHBoxLayout;
     layout6->addWidget(send);
     QVBoxLayout *layout22=new QVBoxLayout;
     layout22->addLayout(layout1);
     layout22->addLayout(layout2);
     layout22->addLayout(layout3);
     layout22->addLayout(layout4);
     layout22->addLayout(layout5);
     layout22->addLayout(layout6);
   //  connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
         connect(sserver,SIGNAL(newConnection()),this,SLOT(newConnection()));
         connect(start,SIGNAL(clicked()),this,SLOT(serverstart()));
         connect(stop,SIGNAL(clicked()),this,SLOT(serverstop()));
         connect(send,SIGNAL(clicked()),this,SLOT(sendmessage()));
      QHBoxLayout *mainlayout=new QHBoxLayout;
      mainlayout->addLayout(layout22);
      swindow->setLayout(mainlayout);
      swindow->show();
}

Server::~Server()
{

}
void Server::serverstart()
{
    QString str;

    if(!sserver->listen(QHostAddress("127.0.0.5"),1234))
    {
        qDebug()<<"server could not started";
        status2->setText("Not Started");
    }
    else
    {
        qDebug()<<"Server Started";
        status2->setText("Started");

    }
}
void Server::serverstop()
{
    sserver->close();
    socket->close();
    status2->setText("Stopped");
}
void Server::sendmessage()
{

    QString str;
    str="You : ";
    str=str+messaget->text();
    socket->write(messaget->text().toStdString().c_str());
    socket->flush();
    socket->waitForBytesWritten(3000);
    messaget->setText("");
    inboxm->append(str);
}
void Server::newConnection()
{
    QString str;
    socket=sserver->nextPendingConnection();
    connectedp->setText(socket->peerAddress().toString());
    str=socket->readAll();
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    inboxm->setText(str);
}
void Server::readyRead()
{
    QString str;
    str=socket->peerAddress().toString()+" : ";
    str=str+socket->readAll();

    inboxm->append(str);
}
