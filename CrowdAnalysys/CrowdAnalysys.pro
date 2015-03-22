#-------------------------------------------------
#
# Project created by QtCreator 2015-03-06T18:17:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = CrowdAnalysys
TEMPLATE = app


SOURCES += main.cpp\
    graphview.cpp \
    qcpdocumentobject.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    graphview.h \
    qcpdocumentobject.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    graphview.ui
