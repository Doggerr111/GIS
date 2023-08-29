#ifndef LIPPOINTGRAPHICSITEM_H
#define LIPPOINTGRAPHICSITEM_H

#include <QGraphicsItem>
#include <lippoint.h>
#include <QPen>
#include <QPainter>

class LIPPointGraphicsItem : public QGraphicsItem
{
public:
    LIPPointGraphicsItem();
    void setPoint(LIPPoint *new_point);
    void setBoundingRect(QRectF);
private:
    LIPPoint *point;
    QRectF bBox;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LIPPOINTGRAPHICSITEM_H
