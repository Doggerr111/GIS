#include "lippolygonlayer.h"
#include <QDebug>
LIPPolygonLayer::LIPPolygonLayer(OGRLayer *l, QString name, QString path, GDALDataset *ds)
    : LIPVectorLayer(l, path, ds),
      //layer{l},
      GISName{name},
      fileName{path}
{

}

QString LIPPolygonLayer::returnGISName()
{
    return GISName;

}

QVector<QVector<LIPPoint *> > LIPPolygonLayer::returnCords()
{
    if (layer!=nullptr)
    {
        layer->GetName();
        OGRFeature *shpFeature;
        layer->ResetReading();
        int counter=0;
        while ((shpFeature = layer->GetNextFeature()) != NULL)
        {
            counter++;
            OGRGeometry *poGeometry = shpFeature->GetGeometryRef();
            int count = shpFeature->GetGeomFieldCount();

            for (int i=0;i<shpFeature->GetGeomFieldCount();i++)
            {
                if (poGeometry != NULL)
                {
                    OGRwkbGeometryType type=poGeometry->getGeometryType();

                    QVector<LIPPoint*> vect;
                    OGRPolygon *polygon = (OGRPolygon *)poGeometry;
                    OGRLinearRing* ring = polygon->getExteriorRing();

                    for (int i = 0; i < ring->getNumPoints(); i++)
                    {
                        OGRPoint point;
                        LIPPoint *pointN = new LIPPoint();
                        ring->getPoint(i, &point);
                        double x = point.getX();
                        double y = point.getY();
                        pointN->setX(x);
                        pointN->setY(y);
                        vect.append(pointN);
                    }

                    coordinates.append(vect);

                }
            }
        }
        return coordinates;
    }
}

void LIPPolygonLayer::setFileName(QString path)
{
    fileName=path;
}

QString LIPPolygonLayer::getFileName()
{
    return fileName;
}

void LIPPolygonLayer::setMapFeatures()
{
    QVector<QVector<LIPPoint*>> vect = returnCords();
    qDebug()<<"КОЛИЧЕСТВО ОБЪЕКТОВ:" + QString::number(vect.size());
    for (int i=0; i<vect.size(); i++)
    {
        LIPPolygonGraphicsItem *el = new LIPPolygonGraphicsItem();

        el->setPoints(vect.at(i));

        mapFeatures.append(el);
        qDebug()<<mapFeatures.at(i);
    }

}

QVector<LIPPolygonGraphicsItem*> LIPPolygonLayer::returnMapFeatures()
{
    return mapFeatures;
}

void LIPPolygonLayer::addFeature(QVector<QPointF> coords, QVector<LIPAttribute> attrs)
{
    OGRFeature *newFeature = OGRFeature::CreateFeature(layer->GetLayerDefn());
    OGRwkbGeometryType t= layer->GetLayerDefn()->GetGeomType();
    OGRPolygon *polygon = new OGRPolygon();
    OGRLinearRing ring;// = new OGRLinearRing;// = polygon->getExteriorRing();
    //layer->StartTransaction();
    LIPPolygonGraphicsItem *el = new LIPPolygonGraphicsItem();
    QVector<LIPPoint*> pointPtrs;
    for (int i = 0; i < coords.size(); i++)
    {
        LIPPoint* p = new LIPPoint;
        p->setX(coords[i].x());
        p->setY(coords[i].y());
        pointPtrs.append(p);
    }
    el->setPoints(pointPtrs);
    mapFeatures.append(el);
    for (int i=0; i<coords.size(); i++)
    {
        ring.addPoint(coords.at(i).x(), coords.at(i).y());
    }
    ring.closeRings(); //ОБЯЗАТЕЛЬНО ПРИ СОЗДАНИИ ПОЛИГОНАЛЬНОГО ОБЬЕКТА!! ИНАЧЕ ОШИБКИ ПРИ РАБОТЕ СО СЛОЕМ
    OGRErr R=polygon->addRingDirectly(&ring);


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

    newFeature->SetGeometry(polygon);
    newFeature->SetFID(layer->GetFeatureCount());

    // Добавление объекта к слою
    OGRErr er1 = layer->StartTransaction();
    OGRErr er = layer->CreateFeature(newFeature);
    layer->GetLayerDefn()->SetGeomType(wkbPolygon);
    layer->SetSpatialFilter(nullptr);
    er1= layer->CommitTransaction();
    layer->SyncToDisk();
    setMapFeatures();
    //GDALClose(layer);

    OGRFeature::DestroyFeature(newFeature);
}
