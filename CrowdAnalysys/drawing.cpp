#include "drawing.h"
#include <QtAlgorithms>

#define PI 3.14159265


Drawing::Drawing(QGraphicsView * graphics_view,QGraphicsScene * drawing_scene)
{
    view = graphics_view;
    scene = drawing_scene;

}


void Drawing::SetNumberOfLocations(int number){
    double theta = 180;
    double r = 150;

    int n = 0;

    double theta_step = 360 / number;

    qDeleteAll(scene->items());

    // create the center location
    scene->addEllipse(0,0,60,60,QPen(QBrush(Qt::black),1));
    //scene->addWidget(new Dlocation(this));

    //QFont font("times", 24);



    QGraphicsTextItem * io = new QGraphicsTextItem;

    QFontMetrics fm(io->font());
    io->setPos(-fm.width("Stay\nHome")/2,fm.height()+30);
    io->setPlainText("Stay\nHome");

    scene->addItem(io);






    for(n = 1; n <= number; n++){
        theta += theta_step;
        double x = r * cos(theta * PI/180);
        double y = r * sin(theta * PI/180);

        scene->addEllipse(x,y,40,40,QPen(QBrush(Qt::black),1));

        io = new QGraphicsTextItem;
        QString s;
        s.sprintf("Location %d",n);
        io->setPos(-fm.width(s)/2 + x + 10,fm.height() + y+30);
        io->setPlainText(s);

        scene->addItem(io);

    }




    view->show();


}
