#ifndef LIPLINEGRAPHICSITEM_H
#define LIPLINEGRAPHICSITEM_H

#include <QGraphicsItem>
#include <vector/lippoint.h>
#include <vector/lipgraphicsitem.h>
class LIPLineGraphicsItem : public LIPGraphicsItem
{
public:
    LIPLineGraphicsItem();
    ~LIPLineGraphicsItem() = default;
    void setPoints(QVector<LIPPoint*> points);
private:
    QVector<QPointF> vect;

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LIPLINEGRAPHICSITEM_H
