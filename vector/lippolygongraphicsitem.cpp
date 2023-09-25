#include "lippolygongraphicsitem.h"

LIPPolygonGraphicsItem::LIPPolygonGraphicsItem()
{
    setCacheMode(QGraphicsItem::DeviceCoordinateCache);
}

void LIPPolygonGraphicsItem::setPoints(QVector<LIPPoint *> points)
{
    for (int i=0; i<points.size(); i++)
    {
        QPointF p=QPointF(points.at(i)->x(),points.at(i)->y());
        vect.append(p);
    }
}

QRectF LIPPolygonGraphicsItem::boundingRect() const
{
    return(QRectF(0,0,180,180));
}

void LIPPolygonGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setWidthF(0);
    QBrush brush;
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawPolygon(vect);
}
