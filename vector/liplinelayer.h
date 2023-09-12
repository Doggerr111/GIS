#ifndef LIPLINELAYER_H
#define LIPLINELAYER_H
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include <QString>

class LIPLineLayer
{
public:
    LIPLineLayer(OGRLayer *l, QString name);
    QString returnGISName();
private:
    OGRLayer *layer;
    QString GISName;

};

#endif // LIPLINELAYER_H
