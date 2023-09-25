#include "lippointgraphicsitem.h"

LIPPointGraphicsItem::LIPPointGraphicsItem()
{

}

QRectF LIPPointGraphicsItem::boundingRect() const
{
    return QRectF(p->x(),p->y(),0.03,0.03);
}

void LIPPointGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
    pen.setWidthF(0);
    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(QRectF(p->x(),p->y(),0.03,0.03));
    //painter->drawEllipse(p.x(),p.y(),3,3);
}

void LIPPointGraphicsItem::setPoint(LIPPoint *point)
{
    p=point;
}

//QPainterPath LIPPointGraphicsItem::shape() const
//{
//    return QPainterPath();
//}

