#include "lipmapholder.h"

LIPMapHolder::LIPMapHolder(QObject *parent)
    : QGraphicsView{},
      isDraging{false}
{

}

void LIPMapHolder::resizeEvent(QResizeEvent *event)
{
    emit MapHolderResized();
    QGraphicsView::resizeEvent(event);

}

void LIPMapHolder::wheelEvent(QWheelEvent *event)
{

}

void LIPMapHolder::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
    isDraging=true;
    clickPos=event->pos();
}

void LIPMapHolder::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
    isDraging=false;
}

void LIPMapHolder::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
    if (isDraging)
    {
        QPointF delta=clickPos-event->pos();
        clickPos=event->pos();
        centerOn(mapToScene(this->viewport()->rect().center()+delta.toPoint()));
//        QMatrix const matrix = this->matrix().inverted();
//        QRectF visibleRect = matrix.mapRect(this->viewport()->rect());
//        visibleRect.moveTopLeft(matrix.map(QPoint(this->horizontalScrollBar()->value(),
//                                                this->verticalScrollBar()->value())));
//        int x=visibleRect.x()+mapToScene(event->pos()).x()-mapToScene(clickPos).x();
//        int y=visibleRect.y()+mapToScene(event->pos()).y()-mapToScene(clickPos).y();
//        QRectF rect(x,y,visibleRect.width(), visibleRect.height());
//        this->fitInView(rect);
        //setSceneRect(rect);
    }
}


