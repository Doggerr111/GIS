#ifndef LIPPOLYGONLAYER_H
#define LIPPOLYGONLAYER_H
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include <QString>
#include "lipvectorlayer.h"
#include "vector/lippoint.h"

class LIPPolygonLayer: public LIPVectorLayer
{
public:
    LIPPolygonLayer(OGRLayer *l, QString name);
    QString returnGISName();
    QVector<QVector<LIPPoint*>>  returnCords();
private:
    QVector<QVector<LIPPoint*>> coordinates;
    OGRLayer *layer;
    QString GISName;
};

#endif // LIPPOLYGONLAYER_H
