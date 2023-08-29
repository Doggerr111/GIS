#include "lippointgraphicsitem.h"

LIPPointGraphicsItem::LIPPointGraphicsItem():
    QGraphicsItem(),
    bBox{QRectF(0,0,0,0)}
{

}

void LIPPointGraphicsItem::setPoint(LIPPoint *new_point)
{
    point = new LIPPoint;
    point=new_point;
}

void LIPPointGraphicsItem::setBoundingRect(QRectF rect)
{
    if (rect.isValid())
        bBox=rect;
}

QRectF LIPPointGraphicsItem::boundingRect() const
{
    return (QRectF(-180,-90,360,180));
}

void LIPPointGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setWidth(qreal(0.001));
    painter->setPen(pen);
    painter->drawEllipse(QPointF(point->x(),point->y()),0.001,0.001);
    //painter->drawPoint(point->x(),point->y());

}
