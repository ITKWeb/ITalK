#-------------------------------------------------
#
# Project created by QtCreator 2013-05-28T09:31:50
#
#-------------------------------------------------

QT       += core gui

TARGET = ITalK
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    user.cpp \
    group.cpp \
    message.cpp \
    commands.cpp \
    View/mainpage.cpp \
    View/italkmainwindow.cpp

HEADERS  += mainwindow.h \
    user.h \
    group.h \
    message.h \
    commands.h \
    View/mainpage.h \
    View/italkmainwindow.h

FORMS    += mainwindow.ui \
    View/italkmainwindow.ui
