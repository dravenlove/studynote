#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //对于主窗口,坐标系统相对于屏幕
    //原点:相对于屏幕左上角
    //x向右递增
    //y向下递增
    resize(1000,1000);
    move(100,100);

    QPushButton *b1 = new QPushButton(this);
    b1->move(100,100);//子窗口的坐标系是相对于父窗口的,坐标原点为父窗口左上角x,y与上同
    b1->setText("huahuahua");
    b1->resize(100,100);

    QPushButton *b2 = new QPushButton(b1);
    b2->move(10,10);
    b2->setText("haha");

    myButton *b3 = new myButton(this);
    b3->move(30,30);
    b3->setText("123123222");

    //1.指定父对象后     2.直接或间接继承与QObject
    //上面这两种情况适用于下面
    //子对象如果是动态分配空间用new,不用delete手动释放
    //系统会在析构函数前将他们释放
}

MyWidget::~MyWidget()
{
}

