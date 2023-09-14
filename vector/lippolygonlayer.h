#ifndef LIPPOLYGONLAYER_H
#define LIPPOLYGONLAYER_H
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include <QString>
#include "lipvectorlayer.h"

class LIPPolygonLayer: public LIPVectorLayer
{
public:
    LIPPolygonLayer(OGRLayer *l, QString name);
    QString returnGISName();
private:
    OGRLayer *layer;
    QString GISName;
};

#endif // LIPPOLYGONLAYER_H
