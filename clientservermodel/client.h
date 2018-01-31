#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QTextEdit>
#include <QTcpSocket>

class client : public QMainWindow
{
    Q_OBJECT
public:
    explicit client(QWidget *parent = 0);
    ~client();

signals:

public slots:
    void connectip();
    void sendmessage();
    void disconnectcon();
    void readyRead();
private:
    QLabel *iplabel;
    QLabel *constate;
    QLabel *portlabel;
    QLabel *inboxl;
    QLabel *messagelabel;
    QLineEdit *ip;
    QLineEdit *port;
    QLineEdit *message;
    QTextEdit *inbox;
    QPushButton *connectP;
    QPushButton *send;
    QPushButton *disconnect;
    QTcpSocket *socket;
};

#endif // CLIENT_H
