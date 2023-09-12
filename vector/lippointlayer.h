#ifndef LIPPOINTLAYER_H
#define LIPPOINTLAYER_H
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include <QString>
class LIPPointLayer
{
public:
    LIPPointLayer(OGRLayer *l, QString name);
    QString returnGISName();
private:
    OGRLayer *layer;
    QString GISName;


};

#endif // LIPPOINTLAYER_H
