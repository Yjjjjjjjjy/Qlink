#include "qlink.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLink w;
    w.show();
    return a.exec();
}
