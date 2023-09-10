#include "liplayercreator.h"

LIPLayerCreator::LIPLayerCreator(LIPGeometryType type, QString name)
{
    GDALAllRegister();
    OGRRegisterAll();
    QByteArray ba = name.toLocal8Bit();
    const char *nameChar = ba.data();
    switch (type)
    {
    case LIPGeometryType::LIPPoint: //если создаем точечный слой
    {
        const char *pszDriverName = "ESRI Shapefile"; //toDO выбор драйвера пользователем
        GDALDriver *poDriver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(pszDriverName);
        GDALDataset *poDs = poDriver->Create(nameChar, 0, 0, 0, GDT_Unknown, NULL);
        layer = poDs->CreateLayer(nameChar, NULL, wkbPoint, NULL);
        if (layer == NULL)
        {
            //cout << "Layer creation failed!" << endl;
        }
        else
        {

        }
    }
        break;
    case LIPGeometryType::LIPLineString: //если создаем линейный слой
    {
        const char *pszDriverName = "ESRI Shapefile"; //toDO выбор драйвера пользователем
        GDALDriver *poDriver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(pszDriverName);
        GDALDataset *poDs = poDriver->Create(nameChar, 0, 0, 0, GDT_Unknown, NULL);
        layer = poDs->CreateLayer(nameChar, NULL, wkbLineString, NULL);
        if (layer == NULL)
        {
            //cout << "Layer creation failed!" << endl;
        }
        else
        {

        }
    }
        break;
    case LIPGeometryType::LIPPolygon: //если создаем полигональный слой
    {
        const char *pszDriverName = "ESRI Shapefile"; //toDO выбор драйвера пользователем
        GDALDriver *poDriver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(pszDriverName);
        GDALDataset *poDs = poDriver->Create(nameChar, 0, 0, 0, GDT_Unknown, NULL);
        layer = poDs->CreateLayer(nameChar, NULL, wkbPolygon, NULL);
        if (layer == NULL)
        {
            //cout << "Layer creation failed!" << endl;
        }
        else
        {
        }
    }
    }


OGRFieldDefn poFieldID("ID", OFTInteger);
poFieldID.SetWidth(40);
OGRFieldDefn poFieldType("Type", OFTInteger);
poFieldType.SetWidth(40);
if (layer->CreateField(&poFieldID) != OGRERR_NONE) {
    //cout << "ID field creation failed" << endl;
}
if (layer->CreateField(&poFieldType) != OGRERR_NONE) {
    //cout << "Type field creation failed" << endl;
}

// Picture
int line_N = 90;
//OGRMultiPoint point;
//for (int i = 0; i < line_N; i++) {
//    OGRFeature *poFeature = OGRFeature::CreateFeature(poLayer->GetLayerDefn());
//    poFeature->SetField("ID", i);
//    poFeature->SetField("Type", i);

//    OGRPoint p(i,i);
//    point.addGeometry(&p);
//    poFeature->SetGeometry(&p);

//    if (layer->CreateFeature(poFeature) != OGRERR_NONE) {
//        //cout << "Failed to create feature in shapefile" << endl;
//    }
//    OGRFeature::DestroyFeature(poFeature);
//}
//GDALClose(poDs);


}
