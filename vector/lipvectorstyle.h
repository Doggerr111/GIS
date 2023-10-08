#ifndef LIPVECTORSTYLE_H
#define LIPVECTORSTYLE_H
#include <QPainter>
#include <QPen>
#include <QBrush>
#include "liptypes.h"
#include <QApplication>
#include <QScreen>
class LIPVectorStyle
{
public:
    LIPVectorStyle();
    void setStyleUnit(LIPStyleUnit units);
    void setPen(QPen pen);
    void setWidthMM(double width);
    void setWidth(double width);
    void setPenColor(QColor penCol);

    void setBrush(QBrush brush);
    void setBrushColor(QColor brCol);
    QPen getPen();
    QBrush getBrush();
    static double pixelToMM(double pix);
    static double MMToPixel(double mm);
private:

    LIPStyleUnit mStyleUnit;
    QPen mPen;
    QBrush mBrush;
    double mSceneScaleFact;




};

#endif // LIPVECTORSTYLE_H
