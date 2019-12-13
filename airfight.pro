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
    game.cpp \
    playerplane.cpp \
    enemyplane.cpp \
    actor.cpp \
    plane.cpp \
    shootingactor.cpp \
    movingactor.cpp \
    projectile.cpp

HEADERS  += \
    game.h \
    actor.h \
    movingactor.h \
    shootingactor.h \
    projectile.h \
    plane.h \
    playerplane.h \
    enemyplane.h

FORMS    += mainwindow.ui

RESOURCES = application.qrc

CONFIG += console
