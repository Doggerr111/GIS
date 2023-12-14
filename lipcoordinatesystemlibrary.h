#ifndef LIPCOORDINATESYSTEMLIBRARY_H
#define LIPCOORDINATESYSTEMLIBRARY_H
#include "lipcoordinatesystem.h"
#include <QVector>
class LIPCoordinateSystemLibrary
{
public:
    LIPCoordinateSystemLibrary();
    QVector<LIPCoordinateSystem> getCRSLib();
private:
    QVector<LIPCoordinateSystem> mCRSLib;
};

#endif // LIPCOORDINATESYSTEMLIBRARY_H
