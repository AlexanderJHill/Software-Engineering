#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//! \file mainwindow.h 
//! \brief mainwindow creates the primary GUI display

#include <QMainWindow>
#include "graphview.h"
#include "UserSettings.h"
#include "../Agent/spot.h"
#include <QVector>

QVector<double>getNumber();
QVector<double>getNumber2();
QVector<double>getNumber3();
QVector<double>getNumber4();
QVector<double>getNumber5();
void setTime(int init);
int getTime();

namespace Ui {
class MainWindow;
}

//!
//! \brief The MainWindow class
//! Provides the Main windows for the Fisher sim project.
//!
QVector<double> getSpot();
class MainWindow : public QMainWindow, public UserSettings
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //!
    //! \brief Sends a string to the simulation log.
    //! \param text to display in the log.
    //!
    void log(const QString& text);
    friend class Graphview;

private slots:
friend double getSpotppp();
    void on_fishers_valueChanged(int value);
    void on_locations_valueChanged(int value);
    void on_fishtypes_valueChanged(int value);
    void on_fishpop_valueChanged(int value);
    void on_runtime_valueChanged(int value);

    void on_lineEdit_0_textEdited(const QString &arg1);
    void on_lineEdit_1_textEdited(const QString &arg1);
    void on_lineEdit_2_textEdited(const QString &arg1);
    void on_lineEdit_3_textEdited(const QString &arg1);
    void on_lineEdit_4_textEdited(const QString &arg1);

    void on_weather_clicked();

    void on_reportButton_clicked();

    void on_simulateButton_clicked();

    void startSimulate(int fisherNum, int fishLoc, int fishType, int fishPop, int fishTemp, int runtime);
    void calculateSpot(int fisherNum, int fishLoc );

protected:
    Ui::MainWindow *ui;
    QString settings;
    bool simulated = false;

};

#endif // MAINWINDOW_H
