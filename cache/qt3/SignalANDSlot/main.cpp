
#include "mainwidget.h"
#include "subwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;//先MainWidget执行构造函数
    w.show();
    return a.exec();
}
