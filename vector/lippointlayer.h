#ifndef LIPPOINTLAYER_H
#define LIPPOINTLAYER_H
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include <QString>
#include <vector/lipvectorlayer.h>
#include "lippoint.h"
class LIPPointLayer: public LIPVectorLayer
{
public:
    LIPPointLayer(OGRLayer *l, QString name);
    QString returnGISName();
    QVector<LIPPoint*> returnCords();
private:
    OGRLayer *layer;
    QString GISName;
    QVector<LIPPoint*> coordinates;


};

#endif // LIPPOINTLAYER_H
