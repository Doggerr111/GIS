#include "liplinelayer.h"
#include <QDebug>
LIPLineLayer::LIPLineLayer(OGRLayer *l, QString name)
    : layer{l},
      GISName(name)
{
    if (l==nullptr)
    {

    }
}

LIPLineLayer::LIPLineLayer(QString fileName)
{
    QByteArray ba = fileName.toLocal8Bit();
    const char *nameChar = ba.data();
    char** ppszOptions = NULL;
    ppszOptions = CSLSetNameValue(ppszOptions, "ENCODING", "UTF-8");
    CPLSetConfigOption("SHAPE_ENCODING","");
    GDALDataset *shpDS = (GDALDataset *)GDALOpenEx(nameChar, GDAL_OF_VECTOR, NULL, NULL, NULL);
    if (shpDS == NULL)
    {
        qDebug()<<"Error:cant read this shp file: " + QString(fileName);
        delete this;
    }
    int c=shpDS->GetLayers().size();
    qDebug()<<QString::number(c);
    layer = shpDS->GetLayer(0);
}

QString LIPLineLayer::returnGISName()
{
    return GISName;
}

QVector<LIPPoint *> LIPLineLayer::returnCords()
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


                    OGRLineString *line = (OGRLineString *)poGeometry;
                    for (int i = 0; i < line->getNumPoints(); i++)
                    {
                        LIPPoint *point = new LIPPoint();
                        point->setX(line->getX(i));
                        point->setY(line->getY(i));
                        coordinates.append(point);
                        qDebug()<<"wkbLineString %d: x=%g y=%g z=%g\n", i, line->getX(i), line->getY(i), line->getZ(i);
                    }

                }
            }

        }
        return coordinates;
    }

}
