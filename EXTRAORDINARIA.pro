#-------------------------------------------------
#
# Project created by QtCreator 2015-07-01T13:27:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EXTRAORDINARIA
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    dialog_alumnos.cpp \
    dialog_reuniones.cpp \
    list.cpp \
    node.cpp \
    alumno.cpp \
    reunion.cpp \
    fecha.cpp

HEADERS  += mainwindow.h \
    dialog_alumnos.h \
    dialog_reuniones.h \
    list.h \
    node.h \
    alumno.h \
    reunion.h \
    fecha.h

FORMS    += mainwindow.ui \
    dialog_alumnos.ui \
    dialog_reuniones.ui
