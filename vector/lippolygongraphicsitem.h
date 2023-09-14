#ifndef LIPPOLYGONGRAPHICSITEM_H
#define LIPPOLYGONGRAPHICSITEM_H

#include <QGraphicsItem>
#include <QPen>
#include <QPainter>
#include <vector/lippoint.h>
class LIPPolygonGraphicsItem : public QGraphicsItem
{
public:
    LIPPolygonGraphicsItem();
    void setPoints(QVector<LIPPoint*> points);
private:
    QVector<QPointF> vect;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LIPPOLYGONGRAPHICSITEM_H
