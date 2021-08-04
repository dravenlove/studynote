#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //添加菜单栏指针
    QMenuBar *mBar=menuBar();
    //设置菜单栏
    //setMenuBar(mBar);
    //添加菜单栏上的功能
   QMenu *menu=mBar->addMenu("dialog");
    //添加菜单栏上功能里面的内容
    QAction *p1 =menu->addAction("modal dialog");
    //添加模态对话框,triggered为触发
    connect(p1,&QAction::triggered,
            [=]()
            {
               QDialog dlg;
               //exec()等待用户操作完成才往下执行
               dlg.resize(1000,1000);
               dlg.exec();
               qDebug()<<"fat girl";
            }
            );

    //添加非模态对话框
    QAction *p2 =menu->addAction("!modal dialog");
    connect(p2,&QAction::triggered,
            [=]()
            {

               //exec()等待用户操作完成才往下执行
               dlg1.resize(1000,1000);
               dlg1.show();
               qDebug()<<"tall girl";

               //另一种方法
               //QDialog *p3=new QDialog();

               //p3->show();
               //这种方法有弊端,当程序未关闭的时候
               //每按一次这个按钮会分配一次空间
               //只有结束程序才会delete
               //还可以给他设置属性
               //p3->setAttribute();这个函数里面有可以关闭时自动回收内存

    }
            );

    QAction *p3 =menu->addAction("about dialog");
    //添加关于对话框,triggered为触发
    connect(p3,&QAction::triggered,
            [=]()
            {
                QMessageBox::about(this,"about","about application");


               //QDialog dlg;
               //exec()等待用户操作完成才往下执行
               //dlg.resize(1000,1000);
               //dlg.exec();
               //qDebug()<<"fat girl";
            }
            );
    QAction *p4 =menu->addAction("question dialog");
    //添加关于对话框,triggered为触发
    connect(p4,&QAction::triggered,
            [=]()
            {
                int ret=QMessageBox::question(this,"question1","Are you OK?",QMessageBox::Ok);
                //"Are you OK?",后面可以添加自选按钮参数如,QMessageBox::OK,默认的话为Yes和No
                  switch (ret)
                  {
                  case QMessageBox::Yes:
                      qDebug()<<"OK!";
                      break;
                  case QMessageBox::No:
                      qDebug()<<"NO!";
                      break;
                  default:
                      break;
                  }

               //QDialog dlg;
               //exec()等待用户操作完成才往下执行
               //dlg.resize(1000,1000);
               //dlg.exec();
               //qDebug()<<"fat girl";
            }
            );


    QAction *p5 =menu->addAction("File dialog");
    //添加文件对话框,triggered为触发
    connect(p5,&QAction::triggered,
            [=]()
            {
                //获取打开文件路径this父窗口,open为文件窗口标题,最后一个为选择打开文件的路径一字符串形式
                QString path=QFileDialog::getOpenFileName(this,"open","../","source(*.cpp *.h;;"
                "Text(*.txt);;"
                "All(*.*)");
                qDebug()<<path;

               //QDialog dlg;
               //exec()等待用户操作完成才往下执行
               //dlg.resize(1000,1000);
               //dlg.exec();
               //qDebug()<<"fat girl";
            }
            );

}

MainWindow::~MainWindow()
{
}

