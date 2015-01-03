#-------------------------------------------------
#
# Project created by QtCreator 2014-11-02T18:57:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_Test1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Player.cpp \
    InternetConn.cpp \
    Parameter.cpp \
    Exercise.cpp

HEADERS  += mainwindow.h \
    Player.h \
    Parameter.h \
    InternetConn.h \
    Exercise.h

FORMS    += mainwindow.ui

OTHER_FILES +=
