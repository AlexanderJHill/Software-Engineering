#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//! \file mainwindow.h 
//! \brief mainwindow creates the primary GUI display

#include <QMainWindow>
#include "graphview.h"
#include "UserSettings.h"

namespace Ui {
class MainWindow;
}

//!
//! \brief The MainWindow class
//! Provides the Main windows for the Fisher sim project.
//!
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


private slots:
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



private:
    Ui::MainWindow *ui;
    QString settings;
    bool simulated = false;
};

#endif // MAINWINDOW_H
