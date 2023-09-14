#include "liplinegraphicsitem.h"

LIPLineGraphicsITem::LIPLineGraphicsITem()
{

}

void LIPLineGraphicsITem::setPoints(QVector<LIPPoint *> points)
{
    for (int i=0; i<points.size(); i++)
    {
        QPointF p=QPointF(points.at(i)->x(),points.at(i)->y());
        vect.append(p);
    }
    //vect=points;
}

QRectF LIPLineGraphicsITem::boundingRect() const
{
    return(QRectF(0,0,180,180));
}

void LIPLineGraphicsITem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setWidthF(0);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
    painter->drawPolyline(vect);
}
