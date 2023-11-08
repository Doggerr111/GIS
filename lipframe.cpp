#include "lipframe.h"

LIPFrame::LIPFrame(QWidget *parent)
    : QFrame(parent)
{
    setMouseTracking(true);
}


void LIPFrame::enterEvent(QEvent *event)
{
    QPoint pos = mapFromGlobal(QCursor::pos());
    if (pos.x() <= 2 || pos.x() >= width() - 2 || pos.y() <= 2 || pos.y() >= height() - 2)
    {
        setCursor(Qt::SizeAllCursor);
    }
    else
    {
        setCursor(Qt::ArrowCursor);
    }
}

void LIPFrame::leaveEvent(QEvent *event)
{
    setCursor(Qt::ArrowCursor);
}


void LIPFrame::mousePressEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    if (pos.x() > 2 && pos.x() < width() - 2 && pos.y() > 2 && pos.y() < height() - 2 && event->buttons() == Qt::LeftButton)
    {
        mIsResizing = true;
        mStartPoint = pos;
    }
}

void LIPFrame::mouseReleaseEvent(QMouseEvent *event)
{
}

void LIPFrame::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    if (pos.x() > 2 && pos.x() < width() - 2 && pos.y() > 2 && pos.y() < height() - 2)
    {
        setCursor(Qt::ArrowCursor);
    }
    else
    {
        QFrame::mouseMoveEvent(event);
    }
    if (mIsResizing)
    {
        QPoint newPos = mapToParent(event->pos());
        int deltaX = newPos.x() - mapToParent(mStartPoint).x();
        int deltaY = newPos.y() - mapToParent(mStartPoint).y();
        resize(size().width() + deltaX, size().height() + deltaY);
        mStartPoint = event->pos();
    }
}
