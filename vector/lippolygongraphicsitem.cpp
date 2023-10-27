#include "lippolygongraphicsitem.h"

LIPPolygonGraphicsItem::LIPPolygonGraphicsItem()
    :   LIPGraphicsItem()
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
    QPen pen = mPen;
    pen.setWidthF(mPen.widthF()/mSceneScale);
    painter->setPen(pen);
    painter->setBrush(mBrush);
    painter->drawPolygon(vect);
}
