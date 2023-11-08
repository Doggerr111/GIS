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


//OGRFieldDefn poFieldID("ID", OFTInteger);
//poFieldID.SetWidth(40);
//OGRFieldDefn poFieldType("Type", OFTInteger);
//poFieldType.SetWidth(40);
//if (layer->CreateField(&poFieldID) != OGRERR_NONE) {
//    //cout << "ID field creation failed" << endl;
//}
//if (layer->CreateField(&poFieldType) != OGRERR_NONE) {
//    //cout << "Type field creation failed" << endl;
//}


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

void LIPLayerCreator::createAttribute(LIPAttributeType type, QString name)
{
    bool typeFlag = false;
    QByteArray ba = name.toLocal8Bit();
    const char *nameChar = ba.data();
    switch (type)
    {
    case LIPAttributeType::INT32:
    {
            OGRFieldDefn poField(nameChar, OFTInteger); //создаем аттрибут
            poField.SetWidth(40);
            if (layer->CreateField(&poField) != OGRERR_NONE)
            {
                //cout << "ID field creation failed" << endl;
            }


    }
        break;
    case LIPAttributeType::String:
    {
            OGRFieldDefn poField(nameChar, OFTString); //создаем аттрибут
            poField.SetWidth(40);
            if (layer->CreateField(&poField) != OGRERR_NONE)
            {
                //cout << "ID field creation failed" << endl;
            }

    }
        break;
    case LIPAttributeType::Real:
    {
            OGRFieldDefn poField(nameChar, OFTReal); //создаем аттрибут
            poField.SetWidth(40);
            if (layer->CreateField(&poField) != OGRERR_NONE)
            {
                //cout << "ID field creation failed" << endl;
            }
        }

    }
}

void LIPLayerCreator::setAttribute(LIPAttributeType type, QVariant attribute, QString name) //TODO переработать/удалить
{
//    bool typeFlag = false;
//    QByteArray ba = name.toLocal8Bit();
//    const char *nameChar = ba.data();
//    switch (type)
//    {
//    case LIPAttributeType::INT32:
//    {
//        attribute.toInt(&typeFlag);
//        if (typeFlag)
//        {
//            OGRFeature *Feature = OGRFeature::CreateFeature(layer->GetLayerDefn());
//            Feature->SetField(type, i);
//            Feature->SetField("Type", i);
//        }

//    }
//    case LIPAttributeType::String:
//    {
//        attribute.toString();
//        if (typeFlag)
//        {
//            OGRFieldDefn poField(nameChar, OFTString); //создаем аттрибут
//            poField.SetWidth(40);
//            if (layer->CreateField(&poField) != OGRERR_NONE)
//            {
//                //cout << "ID field creation failed" << endl;
//            }
//        }
//    }
//    case LIPAttributeType::Real:
//    {
//        attribute.toDouble(&typeFlag);
//        if (typeFlag)
//        {
//            OGRFieldDefn poField(nameChar, OFTReal); //создаем аттрибут
//            poField.SetWidth(40);
//            if (layer->CreateField(&poField) != OGRERR_NONE)
//            {
//                //cout << "ID field creation failed" << endl;
//            }
//        }
//    }
    //    }
}

OGRLayer* LIPLayerCreator::returnLayer()
{
    return layer;
}
