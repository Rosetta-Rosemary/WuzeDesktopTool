#include "MainWindow.h"

#include <QApplication>
#include <QStyleFactory>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("fusion"));
    MainWindow w;
    w.show();
    return a.exec();
}