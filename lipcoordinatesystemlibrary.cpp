#include "lipcoordinatesystemlibrary.h"

LIPCoordinateSystemLibrary::LIPCoordinateSystemLibrary()
{
    LIPCoordinateSystem WGS84;
    WGS84.setProj("+proj=longlat +datum=WGS84 +no_defs +type=crs");
    WGS84.setName("WGS 84");
    mCRSLib.append(WGS84);

    LIPCoordinateSystem GSK_2011;
    GSK_2011.setProj("+proj=longlat +ellps=GSK2011 +no_defs +type=crs");
    GSK_2011.setName("ГСК-2011");
    mCRSLib.append(GSK_2011);

    LIPCoordinateSystem PZ_90_11;
    PZ_90_11.setProj("+proj=longlat +a=6378136 +rf=298.257839303 +no_defs +type=crs");
    PZ_90_11.setName("ПЗ-90.11");
    mCRSLib.append(PZ_90_11);
}

QVector<LIPCoordinateSystem> LIPCoordinateSystemLibrary::getCRSLib()
{
    return mCRSLib;
}
