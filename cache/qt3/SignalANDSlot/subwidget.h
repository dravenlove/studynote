#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>


class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);

    void sendSlot();
signals:
    //信号必须由signals关键字声明
    //信号都是void但可以有参数
    //信号就是函数的声明,只需声明,只要声明不用定义
    //用:emit mySignal();

    void mySignals();
    void mySignals(int,QString);

private:
        QPushButton b;
};

#endif // SUBWIDGET_H
