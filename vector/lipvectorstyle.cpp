#include "lipvectorstyle.h"

LIPVectorStyle::LIPVectorStyle()
{

}

void LIPVectorStyle::setStyleUnit(LIPStyleUnit unit)
{
    mStyleUnit=unit;
}

void LIPVectorStyle::setPen(QPen pen)
{
    mPen=pen;
}

void LIPVectorStyle::setWidthMM(double width)
{
     mPen.setWidthF(MMToPixel(width)/mSceneScaleFact);
}

void LIPVectorStyle::setWidth(double width)
{

}

void LIPVectorStyle::setPenColor(QColor penCol)
{
    mPen.setColor(penCol);
}

void LIPVectorStyle::setBrush(QBrush brush)
{
    mBrush=brush;
}

void LIPVectorStyle::setBrushColor(QColor brCol)
{
    mBrush.setColor(brCol);
}

QPen LIPVectorStyle::getPen()
{
    return mPen;
}

QBrush LIPVectorStyle::getBrush()
{
    return mBrush;
}

double LIPVectorStyle::pixelToMM(double pix)
{
    return 0.0;
}

double LIPVectorStyle::MMToPixel(double mm)
{
    const double dots_per_millimeter = (qApp->primaryScreen()->physicalDotsPerInch() / 25.40);
    return mm*dots_per_millimeter;
}
