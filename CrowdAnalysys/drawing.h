#ifndef DRAWING_H
#define DRAWING_H

//! \file drawing.h
//! \brief Provides a method of drawing locations and the number of people in each location.

#include <QMainWindow>
#include <QtWidgets>
#include <QVector>
#include "dlocation.h"

//! \brief Provides a method of drawing locations and the number of people in each location.
//!
//! Drawing is used by the main window to create the real time display. It provides methods
//! to get and set the number of locations and the number of people at each location. Setting
//! different values is not updated on the screen without calling ReDraw.
//!
class Drawing
{
public:
    QGraphicsScene * scene;
    QGraphicsView * view;
    int NumberOfLocations;

    int locationPop[10];


    Drawing(QGraphicsView * graphics_view,QGraphicsScene * drawing_scene);

    void SetNumberOfLocations(int number);
    void DrawPerson(int x, int y);
    double getLocationCenterX(int location);
    double getLocationCenterY(int location);
    void SetLocationPop(int location,int pop);
    void DrawLocationPop(int location);
    void ReDraw();
    void SetDay(int day);
    int CurrentDay;
};

#endif // DRAWING_H
