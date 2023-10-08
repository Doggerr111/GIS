#include "liplinegraphicsitem.h"

LIPLineGraphicsItem::LIPLineGraphicsItem()
{

}

void LIPLineGraphicsItem::setPoints(QVector<LIPPoint *> points)
{
    for (int i=0; i<points.size(); i++)
    {
        QPointF p=QPointF(points.at(i)->x(),points.at(i)->y());
        vect.append(p);
    }
    //vect=points;
}

QRectF LIPLineGraphicsItem::boundingRect() const
{
    return(QRectF(0,0,180,180));
}

void LIPLineGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidthF(0);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
    painter->drawPolyline(vect);
}
