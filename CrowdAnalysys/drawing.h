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

    //Qlist<Dlocation *> locations;


    Drawing(QGraphicsView * graphics_view,QGraphicsScene * drawing_scene);

    void SetNumberOfLocations(int number);

};

#endif // DRAWING_H
