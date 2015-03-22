#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void log(const QString& text);

private slots:
    void on_fishers_valueChanged(int value);
    void on_locations_valueChanged(int value);
    void on_fishtypes_valueChanged(int value);
    void on_fishpop_valueChanged(int value);
    void on_horizontalSlider_4_valueChanged(int value);

    void on_lineEdit_0_textEdited(const QString &arg1);
    void on_lineEdit_1_textEdited(const QString &arg1);
    void on_lineEdit_2_textEdited(const QString &arg1);
    void on_lineEdit_3_textEdited(const QString &arg1);
    void on_lineEdit_4_textEdited(const QString &arg1);

    void on_weather_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Graphview graphview;
};

#endif // MAINWINDOW_H
