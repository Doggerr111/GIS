#include "lipvectorstyle.h"

LIPVectorStyle::LIPVectorStyle()
{

}

void LIPVectorStyle::setStyleUnit(LIPStyleUnit units)
{

}

void LIPVectorStyle::setPen(QPen pen)
{

}

void LIPVectorStyle::setWidthMM(double width)
{
     mPen.setWidthF(MMToPixel(width));
}

void LIPVectorStyle::setWidth(double width)
{

}

void LIPVectorStyle::setPenColor(QColor penCol)
{

}

void LIPVectorStyle::setBrush(QBrush brush)
{

}

void LIPVectorStyle::setBrushColor(QColor brCol)
{

}

QPen LIPVectorStyle::getPen()
{

}

QBrush LIPVectorStyle::getBrush()
{

}

double LIPVectorStyle::pixelToMM(double pix)
{

}

double LIPVectorStyle::MMToPixel(double mm)
{
    const double dots_per_millimeter = (qApp->primaryScreen()->physicalDotsPerInch() / 25.40);
    return mm*dots_per_millimeter;
}
