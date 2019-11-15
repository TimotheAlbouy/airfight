#-------------------------------------------------
#
# Project created by QtCreator 2019-10-21T10:26:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = airfight
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    turret.cpp \
    projectile.cpp

HEADERS  += mainwindow.h \
    game.h \
    actor.h \
    movingactor.h \
    shootingactor.h \
    turret.h \
    projectile.h

FORMS    += mainwindow.ui
