QT += core
QT -= gui

TARGET = FamousPeeps
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    famouspeople.cpp \
    data.cpp

HEADERS += \
    famouspeople.h \
    data.h \
    infotype.h

