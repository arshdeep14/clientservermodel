#include "client.h"

client::client(QWidget *parent) : QMainWindow(parent)
{
    QWidget *window=new QWidget;
    socket=new QTcpSocket(this);
iplabel=new QLabel("IP Address");
portlabel =new QLabel("Port No.");
inboxl=new QLabel("Chat");
constate=new QLabel("");
messagelabel=new QLabel("Message");
ip=new QLineEdit;
port=new QLineEdit;
inbox=new QTextEdit;
message=new QLineEdit;
connectP=new QPushButton("Connect");
send=new QPushButton("Send");
disconnect=new QPushButton("Disconnect");
QHBoxLayout *top1layout=new QHBoxLayout;
top1layout->addWidget(iplabel);
top1layout->addWidget(portlabel);
QHBoxLayout *top2layout=new QHBoxLayout;
top2layout->addWidget(ip);
top2layout->addWidget(port);
top2layout->addWidget(connectP);
QHBoxLayout *bottom1layout=new QHBoxLayout;
bottom1layout->addWidget(messagelabel);
QHBoxLayout *bottom4layout=new QHBoxLayout;
bottom4layout->addWidget(inboxl);
bottom4layout->addWidget(inbox);
QHBoxLayout *bottom2layout=new QHBoxLayout;
bottom2layout->addWidget(message);
bottom2layout->addWidget(send);
QHBoxLayout *bottom3layout=new QHBoxLayout;
bottom3layout->addWidget(disconnect);
QVBoxLayout *leftlayout=new QVBoxLayout;
leftlayout->addLayout(top1layout);
leftlayout->addLayout(top2layout);
leftlayout->addLayout(bottom1layout);
leftlayout->addLayout(bottom4layout);
leftlayout->addLayout(bottom2layout);
leftlayout->addWidget(constate);

leftlayout->addLayout(bottom3layout);
     connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
     connect(connectP,SIGNAL(clicked()),this,SLOT(connectip()));
     connect(send,SIGNAL(clicked()),this,SLOT(sendmessage()));
     connect(disconnect,SIGNAL(clicked()),this,SLOT(disconnectcon()));

QHBoxLayout *mainlayout=new QHBoxLayout;
mainlayout->addLayout(leftlayout);
window->setLayout(mainlayout);
window->show();
setWindowTitle("Client");
}

client::~client()
{

}

void client::connectip()
{

    QString str,str2;
    str=ip->text();
    str2=port->text();
    qDebug()<<str;
    qDebug()<<str2.toUInt();
    socket->connectToHost(str,str2.toInt());

    if(socket->waitForConnected(10000))
    {
        constate->setText("Connected");
    }
    else
        constate->setText("Disconnected");


}
void client::sendmessage()
{
QString str;
str="You : ";
str=str+message->text().toStdString().c_str();
socket->write(message->text().toStdString().c_str());
message->setText("");
inbox->append(str);

}
void client::disconnectcon()
{
socket->close();
constate->setText("Disconnected");
}
void client::readyRead()
{
    QString str;
    str=ip->text()+" : ";
    str=str+socket->readAll();
    inbox->append(str);
}
