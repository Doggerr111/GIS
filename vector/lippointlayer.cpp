#include "lippointlayer.h"

LIPPointLayer::LIPPointLayer(OGRLayer *l, QString name, QString fileName, GDALDataset *dataset)
    : LIPVectorLayer(l, fileName, dataset),
      //layer{l},
      GISName(name)
{

}

QString LIPPointLayer::returnGISName()
{
    return GISName;
}

QVector<LIPPoint *> LIPPointLayer::returnCords()
{
    if (layer!=nullptr)
    {
        layer->GetName();
        OGRFeature *shpFeature;
        layer->ResetReading();
        int counter=0;
        //qDebug()<<shpLayer->GetSpatialRef()->GetEPSGGeogCS();
        while ((shpFeature = layer->GetNextFeature()) != NULL)
        {
            counter++;
//            OGRFeatureDefn *poFDefn = layer->GetLayerDefn();
//            int iField;
//            for (iField = 0; iField < poFDefn->GetFieldCount(); iField++)
//            {
//                OGRFieldDefn *poFieldDefn = poFDefn->GetFieldDefn(iField);
//                if (poFieldDefn->GetType() == OFTInteger)
//                    qDebug()<<"%d, " +  QString::number(shpFeature->GetFieldAsInteger(iField));
//                else if (poFieldDefn->GetType() == OFTInteger64)
//                    qDebug()<<"%lld, "+QString::number( shpFeature->GetFieldAsInteger64(iField));
//                else if (poFieldDefn->GetType() == OFTReal)
//                    qDebug()<<"%.3f, "+QString::number(shpFeature->GetFieldAsDouble(iField));
//                else if (poFieldDefn->GetType() == OFTString)
//                    qDebug()<<"%s, " + QString(shpFeature->GetFieldAsString(iField));
//                else
//                    qDebug()<<"%s, " + QString(shpFeature->GetFieldAsString(iField));
//            }
            //printf("\n");
            OGRGeometry *poGeometry = shpFeature->GetGeometryRef();
            int count = shpFeature->GetGeomFieldCount();

            for (int i=0;i<shpFeature->GetGeomFieldCount();i++)
            {
                if (poGeometry != NULL)
                {
                    OGRwkbGeometryType type=poGeometry->getGeometryType();

                    OGRPoint *pointOGR=(OGRPoint*)poGeometry;
                    //qDebug()<<"x_coordinate: "+ QString::number(point->getX()) + "; y_cooordinate: "+ QString::number(point->getY());
                    LIPPoint *point = new LIPPoint();
                    point->setX(pointOGR->getX());
                    point->setY(pointOGR->getY());

                    coordinates.append(point);


                }
            }

        }
        return coordinates;
    }
}

void LIPPointLayer::setMapFeatures()
{
    returnCords();
    mStyle=LIPVectorStyle::createDefaultVectorStyle(LIPGeometryType::LIPPoint);



    for (int i=0; i<coordinates.size(); i++)
    {
        LIPPointGraphicsItem* item = new LIPPointGraphicsItem;
        item->setVectorStyle(mStyle);
        LIPPoint *point = new LIPPoint();
        point->setX(coordinates.at(i)->x());
        point->setY(coordinates.at(i)->y());
        item->setPoint(point);
        mapFeatures.append(item);
    }
}

QVector<LIPPointGraphicsItem *> LIPPointLayer::returnMapFeatures()
{
    return mapFeatures;
}

void LIPPointLayer::setFileName(QString path)
{
    fileName=path;
}

QString LIPPointLayer::getFileName()
{
    return fileName;
}





void LIPPointLayer::addFeature(QVector<QPointF> coords, QVector<LIPAttribute> attrs)
{
    OGRFeature *newFeature = OGRFeature::CreateFeature(layer->GetLayerDefn());
    OGRwkbGeometryType t= layer->GetLayerDefn()->GetGeomType();
    OGRPoint featurePoint;

    //for (int i=0; i<coords.size(); i++)
    //{
    //не проходим по всему вектроу, так как точка только 1 (мультиточки не поддерживаются)
    featurePoint.setX(coords.at(0).x());
    featurePoint.setY(coords.at(0).y());

    LIPPointGraphicsItem* item = new LIPPointGraphicsItem;
    LIPPoint *point = new LIPPoint();
    point->setX(coords.at(0).x());
    point->setY(coords.at(0).y());
    item->setPoint(point);
    mapFeatures.append(item);

    //}
    newFeature->SetGeometry(&featurePoint);
    for (int i=0; i<attrs.size(); i++)
    {
    QString fieldName = attrs.at(i).getName();
    QByteArray fieldNameBa = fieldName.toLocal8Bit();
    const char *fieldNameChar = fieldNameBa.data();
    switch (attrs.at(i).getType())
    {
    case LIPAttributeType::INT32:
        newFeature->SetField(fieldNameChar, attrs.at(i).getValue().toInt());
        break;
    case LIPAttributeType::Real:
        newFeature->SetField(fieldNameChar, attrs.at(i).getValue().toDouble());
        break;
    case LIPAttributeType::String:
        const char *fieldValueChar=attrs.at(i).getValue().toString().toLocal8Bit().data();
        newFeature->SetField(fieldNameChar, fieldValueChar);
        break;
    }
    }

    newFeature->SetFID(layer->GetFeatureCount());

    // Добавление объекта к слою
    OGRErr er1 = layer->StartTransaction();
    OGRErr er = layer->CreateFeature(newFeature);
    layer->GetLayerDefn()->SetGeomType(wkbPolygon);
    layer->SetSpatialFilter(nullptr);
    er1= layer->CommitTransaction();
    layer->SyncToDisk();
    //GDALClose(layer);
    setMapFeatures();
    OGRFeature::DestroyFeature(newFeature);
}

void LIPPointLayer::setStyle(LIPVectorStyle *style)
{
    mStyle=style; //field of vectorLayer
    mStyle->setGeomType(LIPGeometryType::LIPPoint);
    foreach(LIPPointGraphicsItem *item, mapFeatures)
    {
        item->setVectorStyle(style); //задаем стиль для каждого обьекта слоя
    }
}



void LIPPointLayer::setSceneScaleFactor(double factor)
{
    mScaleFactor=factor;
    foreach(LIPPointGraphicsItem* item, mapFeatures)
    {
        item->setScaleFactor(mScaleFactor);
    }
}


void LIPPointLayer::setVisible(bool isVisible)
{
    if (isVisible)
    {
        foreach(LIPPointGraphicsItem *item, mapFeatures)
            item->setVisible(true);
    }
    else
    {
        foreach(LIPPointGraphicsItem *item, mapFeatures)
            item->setVisible(false);
    }
}
