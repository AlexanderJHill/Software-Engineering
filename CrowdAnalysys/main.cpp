#include "mainwindow.h"
#include <QApplication>
#include <QPlainTextEdit>
#include <QTextBrowser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.log("another log test from main.cpp");

    return a.exec();
}
