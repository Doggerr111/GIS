#include "lippointlayer.h"

LIPPointLayer::LIPPointLayer(OGRLayer *l, QString name)
    : layer{l},
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
