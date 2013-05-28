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
        networkthread.cpp \
    View/hometabwidget.cpp \
    View/discussionwidget.cpp \
    View/userpresentationform.cpp \
    View/mainpage.cpp \
    View/italkmainwindow.cpp \
    View/discussion.cpp

HEADERS  += mainwindow.h \
    user.h \
    group.h \
    message.h \
    commands.h \
    View/mainpage.h \
    View/italkmainwindow.h \
    View/hometabwidget.h \
    View/discussionwidget.h \
    View/userpresentationform.h \
    networkmanager.h \
    networkthread.h \
    View/discussion.h

FORMS    += mainwindow.ui \
    View/italkmainwindow.ui \
    View/hometabwidget.ui \
    View/discussionwidget.ui \
    View/userpresentationform.ui \
    View/discussion.ui

OTHER_FILES += \
    config.txt
