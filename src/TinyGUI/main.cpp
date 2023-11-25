#include "TinyGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TinyGUI w;
    w.show();
    return a.exec();
}
