#-------------------------------------------------
#
# Project created by QtCreator 2015-03-06T18:17:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = FisherSim
TEMPLATE = app


SOURCES += main.cpp\
    graphview.cpp \
    qcpdocumentobject.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    UserSettings.cpp \
    agent.cpp \
    randomgenerator.cpp \
    strategy.cpp \
    spot.cpp \
    drawing.cpp \
    dlocation.cpp

HEADERS  += mainwindow.h \
    graphview.h \
    qcpdocumentobject.h \
    qcustomplot.h \
    UserSettings.h \
    agent.h \
    randomgenerator.h \
    strategy.h \
    spot.h \
    drawing.h \
    dlocation.h

FORMS    += mainwindow.ui \
    graphview.ui
