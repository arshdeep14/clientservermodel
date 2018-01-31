#include <QApplication>
#include "client.h"
#include "server.h"

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    client clientob;
    Server serverob;
    app.exec();
}
