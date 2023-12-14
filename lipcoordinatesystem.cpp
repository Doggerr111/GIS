#include "lipcoordinatesystem.h"

LIPCoordinateSystem::LIPCoordinateSystem()
{

}

bool LIPCoordinateSystem::setName(QString name)
{
    mName=name;
}

bool LIPCoordinateSystem::setProj(QString proj)
{
    if (proj.isEmpty())
        return false;
    mProjString=proj;
    QByteArray ba = proj.toLocal8Bit();
    const char *projChar = ba.data();
    if (importFromProj4(projChar) == OGRERR_NONE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool LIPCoordinateSystem::isProjValid(QString proj)
{

}

QString LIPCoordinateSystem::getName()
{
    return mName;
}
