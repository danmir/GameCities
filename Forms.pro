#-------------------------------------------------
#
# Project created by QtCreator 2014-04-10T17:10:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Forms
TEMPLATE = app


SOURCES += main.cpp \
    mydialogwindow.cpp \
    cities.cpp \
    player.cpp \
    gamewindow.cpp

HEADERS  += \
    mydialogwindow.h \
    cities.h \
    player.h \
    gamewindow.h

FORMS    += \
    mydialogwindow.ui \
    gamewindow.ui

RESOURCES += \
    cities.qrc
