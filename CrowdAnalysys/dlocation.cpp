#include "dlocation.h"

// dlocation made by
// Alexander Hill

Dlocation::Dlocation(QWidget *parent)
    : QWidget(parent)
{


}

bool Dlocation::setPop(int number){
    return false;
}

int Dlocation::getPop(void){
    return 0;
}

bool Dlocation::setCenter(int x, int y){

    return 0;
}


void Dlocation::paintEvent(QPaintEvent * /* event */)
{
    static const QPoint points[4] = {
        QPoint(10, 80),
        QPoint(20, 10),
        QPoint(80, 30),
        QPoint(90, 70)
    };

    QRect rect(10, 20, 80, 60);

    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(20, 30);
    path.cubicTo(80, 0, 50, 50, 80, 80);

    int startAngle = 20 * 16;
    int arcLength = 120 * 16;

    QPainter painter(this);
    painter.drawLine(rect.bottomLeft(), rect.topRight());
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));


}
