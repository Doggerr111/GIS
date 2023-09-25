#ifndef LIPVECTORLAYER_H
#define LIPVECTORLAYER_H
#include <qstring.h>
#include <QObject>
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
class LIPVectorLayer
{
public:
    LIPVectorLayer(OGRLayer *l);
    virtual QString returnGISName();
    QString returnFileName();
    virtual ~LIPVectorLayer();
protected:
    OGRLayer *layer;
signals:
    void needRepaint();



};

#endif // LIPVECTORLAYER_H
