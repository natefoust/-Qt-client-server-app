#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    if(!createConnection())
    {
        return 1;
    }

    w.show();
    return a.exec();
}
