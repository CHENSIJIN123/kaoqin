#-------------------------------------------------
#
# Project created by QtCreator 2018-06-17T20:25:20
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT += axcontainer  xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kaoqing
TEMPLATE = app
include (./protocol/protocol.pri)
include (./dealMsg/dealMsg.pri)
include (./docxml/docxml.pri)
include (./statistics/statistics.pri)

SOURCES += main.cpp\
        register_company.cpp \
    register.cpp \
    kaoqin.cpp \
    userwork.cpp \
    daka.cpp \
    forgetcompanyname.cpp \
    increasemanager.cpp \
    person.cpp \
    apply.cpp \

HEADERS  += register_company.h \
    register.h \
    kaoqin.h \
    userwork.h \
    daka.h \
    forgetcompanyname.h \
    increasemanager.h \
    person.h \
    apply.h \

FORMS    += register_company.ui \
    register.ui \
    kaoqin.ui \
    userwork.ui \
    daka.ui \
    forgetcompanyname.ui \
    increasemanager.ui \
    person.ui \
    apply.ui

CONFIG += C++11

CONFIG += qaxcontainer

RESOURCES += \
    image.qrc
