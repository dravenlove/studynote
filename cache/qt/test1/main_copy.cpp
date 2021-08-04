#include "mywidget.h"

//QApplication应用程序类
//Qt头文件没有.h
//头文件和类名一样
#include <QApplication>

int main(int argc, char *argv[])
{
    //有且只有一个应用程序类的对象
    QApplication a(argc, argv);

    //MyWidget继承于QWidget(基类也是一个窗口)

    //MyWidget也是窗口类,故w也是一个窗口
    MyWidget w;

    //窗口创建默认是隐藏的,需要认为显示
    //访问w中的show函数才能访问
    w.show();

    //让程序进入死循环,等待用户输入
    //等待事件的发生
    return a.exec();
}
