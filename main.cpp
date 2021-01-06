#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Connection c;
    bool test=c.createconnection();
    if (test)
    w.show();
    return a.exec();
}
