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
    qcustomplot.cpp \
    UserSettings.cpp \
    ../Agent/agent.cpp \
    ../Agent/randomgenerator.cpp \
    ../Agent/strategy.cpp

HEADERS  += mainwindow.h \
    graphview.h \
    qcpdocumentobject.h \
    qcustomplot.h \
    UserSettings.h \
    ../Agent/agent.h \
    ../Agent/randomgenerator.h \
    ../Agent/strategy.h

FORMS    += mainwindow.ui \
    graphview.ui
