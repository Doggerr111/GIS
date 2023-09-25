#ifndef LIPPOINTLAYER_H
#define LIPPOINTLAYER_H
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include <QString>
#include <vector/lipvectorlayer.h>
#include "lippoint.h"
#include <vector/lippointgraphicsitem.h>
class LIPPointLayer: public LIPVectorLayer
{
public:
    LIPPointLayer(OGRLayer *l, QString name);
    QString returnGISName();
    QVector<LIPPoint*> returnCords();
    void setMapFeatures();
    QVector<LIPPointGraphicsItem*> returnMapFeatures();
    void addFeature(LIPPoint* p);
    void setFileName(QString path);
    QString getFileName();



private:
    //void createMapFeatures();
    OGRLayer *layer;
    QString GISName;
    QVector<LIPPoint*> coordinates;
    QString fileName;
    QVector<LIPPointGraphicsItem*> mapFeatures;




};

#endif // LIPPOINTLAYER_H
