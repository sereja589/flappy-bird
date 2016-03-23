#-------------------------------------------------
#
# Project created by QtCreator 2016-03-13T13:38:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlappyBird2
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    bird.cpp \
    myview.cpp \
    myscene.cpp \
    column.cpp

HEADERS  += \
    game.h \
    bird.h \
    myview.h \
    myscene.h \
    column.h

CONFIG += c++11

DISTFILES +=
