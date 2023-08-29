#include "lipmapscene.h"

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
