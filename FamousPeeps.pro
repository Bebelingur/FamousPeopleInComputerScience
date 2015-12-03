QT += core
QT += sql
QT -= gui

TARGET = FamousPeeps
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    data.cpp \
    ui.cpp \
    services.cpp

HEADERS += \
    data.h \
    infotype.h \
    ui.h \
    services.h
