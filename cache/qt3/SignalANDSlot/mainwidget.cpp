#include "mainwidget.h"
#include <QPushButton>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("111");

    connect(&b1,&QPushButton::pressed,this,&MainWidget::close );
    //&b1信号发出者,指针类型
    //&PushButton::pressed:处理的信号   &发送者的类名::信号名字
    //this:信号接收者
    //&MainWidget::close:槽函数,信号处理函数 &接收的类名::槽函数名称

    //自定义槽
    //qt5:任意成员函数,普通全局函数,静态函数
    //槽函数需要和信号一致(参数,返回值)
    //因为信号都是void所以槽函数也都是void
    connect(b2,&QPushButton::released,this,&MainWidget::myslot);
    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);

    //信号:短信
    //槽函数:接收信息的手机

    setWindowTitle("father");

    b3.setParent(this);
    b3.setText("tab son");
    b3.move(50,50);
    resize(400,300);
    //w.show();
    connect(&b3,&QPushButton::released,this,&MainWidget::change);
    //处理子窗口信号

    //重载函数
    //指针指向函数
    //void fun(){}
    //用一个指针指向他的方法
    //void (*p指针名)()=fun;
    //也可以p=&fun;
    //参数也要一一对应
    //void fun(int){}
    //void (*p)(int)=fun;
    void (SubWidget::*mySignals1)()=&SubWidget::mySignals;
    connect(&w,mySignals1,this,&MainWidget::dealSubWidget);
    void (SubWidget::*mySignals2)(int,QString)=&SubWidget::mySignals;
    connect(&w,mySignals2,this,&MainWidget::dealSlot);

    //上下等同不过一个用qt4一个用qt5

    //qt4信号连接
    //qt4的槽函数必须要有slots关键字修饰
    connect(&w,SIGNAL(mySignals()),this,SLOT(dealSubWidget));
    connect(&w,SIGNAL(mySIgnals(int,QString)),this,SLOT(dealSlot));

    //SIGNAL SLOT他们将函数名字改为字符串不进行错误检查

    //Lambda表达式,匿名函数对象
    //c++11添加的新特性,项目文件CONFIG +=C++11
    //QT配合信号一起使用,非常方便

    QPushButton *b4 =new QPushButton(this);
    b4->setText("Lambda");
    b4->move(150,150);
    connect(b4,&QPushButton::clicked,
            [b4](bool isCheck)
            //[b4]中的内容可以改为[=]把外部所有局部变量和类中所有成员按值传参传入
            //()后面加入 mutable成员将从可读变成可修改
            //[this]类中所有成员按值传参传入
            //[&]:应用符号 把外部所有局部变量
            {
                qDebug()<<"123"<<isCheck;
                b4->setText("456");
               // b2->setText("???");//如果改成=这个将改变b2按钮的名字
             }


            );

}


void MainWidget::myslot()
{
    b2->setText("123");
}
void MainWidget::change()
{
    //子窗口显示
    w.show();
    //父窗口隐藏
    this->hide();
}

void MainWidget::dealSubWidget()
{
    //子窗口隐藏
    w.hide();
    //父窗口显示
    this->show();
}

void MainWidget::dealSlot(int a,QString str)
{
    qDebug()<<a<<str;//转化为UTF-8的方法str.toUtf8().date()
    //str.toUtf8()作用为将str存储数据转换为字节数组QByteArray
    //.date()的作用将字节数组QByteArray转换为char *
}
MainWidget::~MainWidget()
{
}

