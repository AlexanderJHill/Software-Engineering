#include "drawing.h"
#include <QtAlgorithms>

#define PI 3.14159265


Drawing::Drawing(QGraphicsView * graphics_view,QGraphicsScene * drawing_scene)
{
    view = graphics_view;
    scene = drawing_scene;

}


// uses icon from https://www.iconfinder.com/icons/309035/account_human_person_user_icon#size=128
void Drawing::DrawPerson(int x, int y){
    double width = 15;
    double height = 20;

    //scene->addRect(x-width/2,y,width,height);
    //scene->addEllipse(x+width/2-2.5,y,5,5);
    //scene->addLine();
    //scene->addLine(x,y,x+20,y+20);
    QGraphicsPixmapItem * person = new QGraphicsPixmapItem;
    person->setPixmap(QPixmap("user-128.png"));
    person->setScale(0.1);
    QRectF r =  person->boundingRect();

    person->setPos(x-r.width()/20,y);
    scene->addItem(person);

}


void Drawing::SetLocationPop(int location,int pop){
    double x = getLocationCenterX(location);
    double y = getLocationCenterY(location);
    QString s;

    QGraphicsTextItem * io = new QGraphicsTextItem;
    s.sprintf("Population: %d",pop);
    QFontMetrics fm(io->font());
    io->setPos(-fm.width(s)/2 + x,fm.height()+10 + y);
    io->setPlainText(s);

    scene->addItem(io);


}


double Drawing::getLocationCenterX(int location){
    double theta = 180;
    double r = 150;

    double theta_step = 360 / NumberOfLocations;
    theta = location * theta_step;
    return r * cos(theta * PI/180);
}

double Drawing::getLocationCenterY(int location){
    double theta = 180;
    double r = 150;

    double theta_step = 360 / NumberOfLocations;
    theta += location * theta_step;
    return r * sin(theta * PI/180);
}


void Drawing::SetNumberOfLocations(int number){
    double theta = 180;
    double r = 150;

    int n = 0;
    NumberOfLocations = number;
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
        double x = getLocationCenterX(n); // r * cos(theta * PI/180);
        double y = getLocationCenterY(n); // r * sin(theta * PI/180);

        scene->addEllipse(x,y,90,90,QPen(QBrush(Qt::black),1));

        io = new QGraphicsTextItem;
        QString s;
        s.sprintf("Location %d",n);
        io->setPos(-fm.width(s)/2 + x + 10,fm.height() + y+30);
        io->setPlainText(s);

        DrawPerson(x,y);
        scene->addItem(io);

        SetLocationPop(n,50*n);

    }

    view->show();
}
