#include "lipmapscene.h"
#include <QDebug>

LIPMapScene::LIPMapScene(QObject *parent)
    : QGraphicsScene{parent},
      isDraging{false}
{

}

void LIPMapScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit pos_changed(event->scenePos());
    if (isDraging)
    {
//        QPointF delta=clickPos-event->pos();
//        clickPos=event->pos();
//        //centerOn(sceneRect().center()+delta.toPoint());
//        setSceneRect(sceneRect().translated(-delta));
        emit scene_dragging(clickPos,event->scenePos());
    }
}

void LIPMapScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{

}

void LIPMapScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clickPos=event->scenePos();
    isDraging=true;
}

void LIPMapScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    isDraging=false;
}

void LIPMapScene::drawVectorLayer(LIPVectorLayer* layer)
{
    if (layer!=nullptr)
    {
        qDebug()<<"VSE OK!!!";
        LIPPointLayer* new_layer=dynamic_cast<LIPPointLayer*>(layer);
        if (new_layer!=nullptr)
        {
            QVector<LIPPoint*> vect = new_layer->returnCords();
            for (int i=0; i<vect.size(); i++)
            {
                //addEllipse(vect.at(i)->x(), vect.at(i)->y(),0.1,0.1);

                LIPPointGraphicsItem *el = new LIPPointGraphicsItem;
                LIPPoint point;
                point.setX(vect.at(i)->x());
                point.setY(vect.at(i)->y());
                el->setPoint(point);
                addItem(el);
                    //addItem(el);
            }
        }
        else
        {
            LIPLineLayer* new_line_layer=dynamic_cast<LIPLineLayer*>(layer);
            QVector<LIPPoint*> vect = new_line_layer->returnCords();
            LIPLineGraphicsITem *el = new LIPLineGraphicsITem;
            el->setPoints(vect);
            addItem(el);
//            for (int i=0; i<vect.size(); i++)
//            {
//                //addEllipse(vect.at(i)->x(), vect.at(i)->y(),0.1,0.1);

//                LIPPointGraphicsItem *el = new LIPPointGraphicsItem;
//                LIPPoint point;
//                point.setX(vect.at(i)->x());
//                point.setY(vect.at(i)->y());
//                el->setPoint(point);
//                addItem(el);
//        }

    }
    }
}
