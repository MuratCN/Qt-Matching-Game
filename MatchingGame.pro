#-------------------------------------------------
#
# Project created by QtCreator 2017-09-29T14:13:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MatchingGame
TEMPLATE = app


SOURCES += main.cpp\
    gamewindow.cpp \
    matchinggame.cpp \
    tictocgame.cpp

HEADERS  += \
    gamewindow.h \
    matchinggame.h \
    tictocgame.h

FORMS    += \
    gamewindow.ui \
    tictocgame.ui
