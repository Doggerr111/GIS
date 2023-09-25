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
            new_layer->setMapFeatures(); //для создания графических айтемов
            for (int i=0; i<new_layer->returnMapFeatures().size(); i++)
            {
                addItem(new_layer->returnMapFeatures().at(i));
            }
//            QVector<LIPPoint*> vect = new_layer->returnCords();
//            for (int i=0; i<vect.size(); i++)
//            {
//                //addEllipse(vect.at(i)->x(), vect.at(i)->y(),0.1,0.1);

//                LIPPointGraphicsItem *el = new LIPPointGraphicsItem;
//                LIPPoint point;
//                point.setX(vect.at(i)->x());
//                point.setY(vect.at(i)->y());
//                el->setPoint(point);
//                addItem(el);
//                    //addItem(el);
//            }
        }
        else
        {
            LIPLineLayer* new_line_layer=dynamic_cast<LIPLineLayer*>(layer);
            if(new_line_layer!=nullptr)
            {
            QVector<QVector<LIPPoint*>> vect = new_line_layer->returnCords();
            for (int i=0; i<vect.size(); i++)
            {
                LIPLineGraphicsITem *el = new LIPLineGraphicsITem;
                el->setPoints(vect.at(i));
                addItem(el);
            }
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
            else
            {
                LIPPolygonLayer* new_poly_layer=dynamic_cast<LIPPolygonLayer*>(layer);
                QVector<QVector<LIPPoint*>> vect = new_poly_layer->returnCords();
                for (int i=0; i<vect.size(); i++)
                {
                    LIPPolygonGraphicsItem *el = new LIPPolygonGraphicsItem;
                    el->setPoints(vect.at(i));
                    addItem(el);
                }
            }

    }
    }
}

void LIPMapScene::addPointFeature()
{
    delete this;
}
