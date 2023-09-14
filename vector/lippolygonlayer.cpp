#include "lippolygonlayer.h"

LIPPolygonLayer::LIPPolygonLayer(OGRLayer *l, QString name)
    : layer{l},
      GISName(name)
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
