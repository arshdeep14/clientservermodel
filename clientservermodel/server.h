#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTcpServer>
#include <QTextBlock>
#include <QTcpSocket>
#include <QTextEdit>
class Server : public QMainWindow
{
    Q_OBJECT
public:
    explicit Server(QWidget *parent = 0);
    ~Server();

signals:

public slots:
    void serverstart();
    void serverstop();
    void sendmessage();
    void newConnection();
    void readyRead();
private:
    QPushButton *start;
    QPushButton *stop;
    QLabel *status;
    QLabel *status2;
    QLabel *connected;
    QLabel *inbox;
    QLabel *message;
    QLineEdit *connectedp;
    QTextEdit *inboxm;
    QPushButton *send;
    QLineEdit *messaget;
    QTcpServer *sserver;
    QTcpSocket *socket;
};

#endif // SERVER_H
