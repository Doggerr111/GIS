#ifndef LIPLINEGRAPHICSITEM_H
#define LIPLINEGRAPHICSITEM_H

#include <QGraphicsItem>
#include <vector/lippoint.h>
class LIPLineGraphicsItem : public QGraphicsItem
{
public:
    LIPLineGraphicsItem();
    void setPoints(QVector<LIPPoint*> points);
private:
    QVector<QPointF> vect;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LIPLINEGRAPHICSITEM_H
