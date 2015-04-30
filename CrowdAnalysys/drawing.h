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

    int locationPop[10];


    Drawing(QGraphicsView * graphics_view,QGraphicsScene * drawing_scene);

    void SetNumberOfLocations(int number);
    void DrawPerson(int x, int y);
    double getLocationCenterX(int location);
    double getLocationCenterY(int location);
    void SetLocationPop(int location,int pop);
    void DrawLocationPop(int location);
    void ReDraw();
    void Sim(QVector<double> s1,QVector<double> s2,QVector<double> s3,QVector<double> s4,QVector<double> s5);
    void SetDay(int day);
    int CurrentDay;
};

#endif // DRAWING_H
