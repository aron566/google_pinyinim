QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# 生成库文件
TARGET = virtualkeyboard
TEMPLATE = lib
# 只生成静态库
#CONFIG += staticlib
# 导出到dll
DEFINES += VIRTUALKEYBOARD_LIBRARY

# 谷歌拼音库的依赖
#DEFINES += PINYINIME_LIBRARY
include(googlelib/lib.pri)

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customerqpushbutton.cpp \
    keyboard.cpp
#    main.cpp #\单键盘页面测试使用，编译库时不可带入

HEADERS += \
    customerqpushbutton.h \
    keyboard.h \
    virtualkeyboard.h \
    ui_keyboard.h
# 屏蔽，否则打开项目会覆盖相对位置信息
#FORMS += \
#    keyboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
