#include "liplinegraphicsitem.h"

LIPLineGraphicsItem::LIPLineGraphicsItem()
    :   LIPGraphicsItem()
{
    mPen.setWidthF(LIPVectorStyle::MMToPixel(1)/mSceneScale);

}

LIPLineGraphicsItem::~LIPLineGraphicsItem()
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
    QPen pen = mStyle->getPen();
    pen.setWidthF(LIPVectorStyle::MMToPixel(pen.widthF())/mSceneScale);
    painter->setPen(pen);
    //mPen.setWidthF((mPen.widthF())/mSceneScale);
    //painter->setBrush(mBrush);
    painter->drawPolyline(vect);

}
