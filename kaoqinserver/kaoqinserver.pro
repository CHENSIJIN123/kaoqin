#-------------------------------------------------
#
# Project created by QtCreator 2018-07-15T23:12:08
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kaoqinserver
TEMPLATE = app
include (./protocol/protocol.pri)
include (./dealMsg/dealMsg.pri)
include (./database/database.pri)

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
CONFIG += C++11
