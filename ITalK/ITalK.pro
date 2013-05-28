#-------------------------------------------------
#
# Project created by QtCreator 2013-05-28T09:31:50
#
#-------------------------------------------------

QT       += core gui network

TARGET = ITalK
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        user.cpp \
        group.cpp \
        message.cpp \
        commands.cpp \
        networkmanager.cpp \
        networkthread.cpp

HEADERS  += mainwindow.h \
    user.h \
    group.h \
    message.h \
    commands.h \
    networkmanager.h \
    networkthread.h

FORMS    += mainwindow.ui
