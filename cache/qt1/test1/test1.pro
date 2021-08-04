#模块
QT       += core gui


#高于qt4的版本,添加QT += widgets以兼容Qt4
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#源文件
SOURCES += \
    main.cpp \
    mywidget.cpp

#头文件
HEADERS += \
    mywidget.h


FORMS += \
    mywidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
