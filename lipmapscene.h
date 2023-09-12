#ifndef LIPMAPSCENE_H
#define LIPMAPSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include "vector/lippointlayer.h"

class LIPMapScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit LIPMapScene(QObject *parent = nullptr);

    // QGraphicsScene interface
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
signals:
    void pos_changed(QPointF);
    void scene_dragging(QPointF,QPointF);

    // QGraphicsScene interface
protected:
    void wheelEvent(QGraphicsSceneWheelEvent *event);

    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QPointF clickPos;
    bool isDraging;
    QVector<LIPPointLayer*> layers;
};

#endif // LIPMAPSCENE_H
