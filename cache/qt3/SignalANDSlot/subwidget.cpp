#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("son");
    b.setParent(this);
    b.setText("tab father");
    resize(400,300);
    connect(&b,&QPushButton::clicked,this,&SubWidget::sendSlot);
}


void SubWidget::sendSlot()
{
    emit mySignals();
    emit mySignals(250,"my love!");
}
