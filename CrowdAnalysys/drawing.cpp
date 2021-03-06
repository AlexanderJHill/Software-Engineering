#include "drawing.h"
#include <QtAlgorithms>

// drawing made by
// Alexander Hill

#define PI 3.14159265


Drawing::Drawing(QGraphicsView * graphics_view,QGraphicsScene * drawing_scene)
{
    view = graphics_view;
    scene = drawing_scene;

}





// uses icon from https://www.iconfinder.com/icons/309035/account_human_person_user_icon#size=128
// Also consider using http://www.flaticon.com/free-icon/fishing-rod-and-fisher_10965
void Drawing::DrawPerson(int x, int y){

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
    locationPop[location] = pop;

}

void Drawing::SetDay(int day){
    CurrentDay = day;
}

void Drawing::DrawLocationPop(int location){

    double x = getLocationCenterX(location);
    double y = getLocationCenterY(location);
    double offset = - 30;

    if(location == 0){
        x = 0;
        y = 0;
        offset = - 30;
    }else{
        x = getLocationCenterX(location);
        y = getLocationCenterY(location);
        offset = - 30;
    }
    QString s;

    QGraphicsTextItem * io = new QGraphicsTextItem;
    s.sprintf("(%d)",locationPop[location]);
    QFontMetrics fm(io->font());
    io->setPos(-fm.width(s)/2 + x,y + offset - fm.height()); //  fm.height()+10 + y);
    io->setPlainText(s);

    scene->addItem(io);

    // draw the requiered number of people
    //           MaxWidth
    // +------------------------+
    // + p1 | p2 | p3 | p4 | p5 |


    int MaxWidth = 5;
    int MaxRows = 6;
    int PersonOffset = 22;
    if(location == 0){ // the home location can show more rows.
        MaxRows = 7;
        MaxWidth = 10;
        PersonOffset = 45;
    }
    int popLeft = locationPop[location];
    int col = 0;
    int row = 0;
    while(popLeft){
        for(row = 0;popLeft > 0 && row < MaxWidth; row ++){
            popLeft--;
            if(col < MaxRows){
                // if there are more items than can be displayed
                if(col == MaxRows-1 && row == MaxWidth -1 && popLeft > 1){
                     io = new QGraphicsTextItem;
                    QFontMetrics fm(io->font());
                    io->setPos(x-PersonOffset + row * 10 - 8 ,y-25 + col * 10 -5); //  fm.height()+10 + y);
                    io->setPlainText("+");

                    scene->addItem(io);
                }else{
                    DrawPerson(x-PersonOffset + row * 10 ,y-25 + col * 10);
                }
            }
        }
        col++;
    }

}


double Drawing::getLocationCenterX(int location){
    double theta = 150;
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

void Drawing::ReDraw(){
    int n = 0;

    qDeleteAll(scene->items());

    // create the center location
    scene->addEllipse(-70,-70,140,140,QPen(QBrush(Qt::black),4));

    QGraphicsTextItem * io = new QGraphicsTextItem;

    QFont font( "Bavaria" );
    font.setPointSize( 11 );
    font.setWeight( QFont::Bold );

    io->setFont(font);

    QFontMetrics fm(font);
    io->setPos(-fm.width("Home")/2,-fm.height()-45);
    io->setPlainText("Home");
    scene->addItem(io);
    DrawLocationPop(0);


    for(n = 1; n <= NumberOfLocations; n++){
        double x = getLocationCenterX(n); // r * cos(theta * PI/180);
        double y = getLocationCenterY(n); // r * sin(theta * PI/180);

        scene->addEllipse(x-45,y-45,90,90,QPen(QBrush(Qt::black),1));

        io = new QGraphicsTextItem;
        QString s;
        s.sprintf("Location %d",n);
        if(NumberOfLocations > 3 && n == 1)
            io->setPos(45 + x, y - fm.height() - 5);
        else
            io->setPos(-fm.width(s)/2 + x + 0, y - 45 - fm.height() - 5);

        io->setPlainText(s);

        io->setFont(font);

        scene->addItem(io);

        DrawLocationPop(n);

    }


    io = new QGraphicsTextItem;
    QString s;
    s.sprintf("Day %d",CurrentDay );
//    io->setPos(0,view->height() / 2 - 20);
    io->setPos(0,200);
    io->setPlainText(s);

    io->setFont(font);

    scene->addItem(io);




    view->show();

}


void Drawing::SetNumberOfLocations(int number){
    NumberOfLocations = number;
    this->ReDraw();

}
