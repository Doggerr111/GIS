#ifndef LIPPOINTGRAPHICSITEM_H
#define LIPPOINTGRAPHICSITEM_H
#include <QGraphicsItem>
#include <QPainter>
#include "vector/lippoint.h"
class LIPPointGraphicsItem: public QGraphicsItem
{
public:
    LIPPointGraphicsItem();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setPoint(LIPPoint *point);
private:
    LIPPoint *p;

    // QGraphicsItem interface
public:
    //QPainterPath shape() const;
};

#endif // LIPPOINTGRAPHICSITEM_H
