#ifndef DRAWING_H
#define DRAWING_H

#include <QMainWindow>
#include <QtWidgets>
#include <QVector>
#include "dlocation.h"


class Drawing
{
public:
    QGraphicsScene * scene;
    QGraphicsView * view;
    int NumberOfLocations;

    //Qlist<Dlocation *> locations;


    Drawing(QGraphicsView * graphics_view,QGraphicsScene * drawing_scene);

    void SetNumberOfLocations(int number);
    void DrawPerson(int x, int y);
    double getLocationCenterX(int location);
    double getLocationCenterY(int location);
    void SetLocationPop(int location,int pop);

};

#endif // DRAWING_H
