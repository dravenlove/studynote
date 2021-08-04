#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc,char **argv)
{
    QApplication app(argc,argv);

    QWidget w;
    w.setWindowTitle(QString("打你肚子"));


    QPushButton b;
    b.setText("0.0");
    b.setParent(&w);//指定父对象
    b.move(100,100);//移动坐标

    QPushButton b1(&w);
    b1.setText("想吸");

    w.show();

    //如果不指定父对象,对象和对象(窗口和窗口)没有关系,他们各自独立
    //如果指定b指定w为他的父对象,将w放在b上
    //指定父对象:1.setParent 2.通过构造函数传参
    //指定父对象只需要父对象显示
    app.exec();
    return 0;

}
