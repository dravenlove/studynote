#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //菜单栏
    QMenuBar *mBar = menuBar();


    //添加菜单
    QMenu *pFile = mBar->addMenu("File");

    //添加菜单项,添加动作
    QAction *pNew = pFile->addAction("New");

    connect(pNew,&QAction::triggered,
        [=]()
        {
        qDebug()<<"new a cliked";
        });
    pFile->addSeparator();//添加分割线
    QAction *pOpen = pFile->addAction("Open");

    //工具栏:菜单项上的快捷方式

    QToolBar *pBar1 = addToolBar("New1");
    //工具栏添加快捷键
    pBar1->addAction(pNew);
    //定义一个按钮指针
    QPushButton *b =new QPushButton(this);
    //添加控件
    b->setText("haha");
    pBar1->addWidget(b);
    connect(b,&QPushButton::clicked,
            [=]()
        {
        b->setText("who?");
         }
            );

    //状态栏
    QStatusBar *pSta = statusBar();
    //标签
    QLabel *label = new QLabel(this);
    label->setText("Welcome to use!");
   //给状态栏添标签的两种方法
    //下面为第一种
    pSta->addWidget(label);
    //下面为第二种
    pSta->addWidget(new QLabel("love you baby!",this));
    //addWideget为从左往右添加,从右往左添加为addPermanentWidget
    pSta->addPermanentWidget(new QLabel("love you baby!",this));

    //核心控件
    //为文本编辑控件添加指针(分配内存空间)
    QTextEdit *pText = new QTextEdit(this);

    //设置中间窗口函数
    setCentralWidget(pText);
    //浮动窗口
    //为浮动窗口分配指针
    QDockWidget *Dock =new QDockWidget(this);

    addDockWidget(Qt::RightDockWidgetArea,Dock);
    //添加另一个文本编辑器给浮动窗口
    QTextEdit *pText1 = new QTextEdit(this);
    Dock->setWidget(pText1);
}

MainWindow::~MainWindow()
{
}

