#include "wifisafenetwork.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wifisafenetwork w;
    w.show();

    return a.exec();
}
