#ifndef LIPPOINTLAYER_H
#define LIPPOINTLAYER_H
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include <QString>
#include <vector/lipvectorlayer.h>
#include "lippoint.h"
#include <vector/lippointgraphicsitem.h>
#include <QObject>

class LIPPointLayer: public LIPVectorLayer
{

public:
    LIPPointLayer(OGRLayer *l, QString name, QString fileName, GDALDataset* dataset);
    QString returnGISName() override;
    QVector<LIPPoint*> returnCords();
    void setMapFeatures() override;
    QVector<LIPPointGraphicsItem*> returnMapFeatures();
    void addFeature(LIPPoint* p);
    void setFileName(QString path);
    QString getFileName();
    void addFeature(QVector<QPointF> coords, QVector<LIPAttribute> attrs) override;
    void setStyle(LIPVectorStyle *style);

public slots:
    void setSceneScaleFactor(double factor) override;



private:
    //void createMapFeatures();
    //OGRLayer *layer;
    QString GISName;
    QVector<LIPPoint*> coordinates;
    QString fileName;
    QVector<LIPPointGraphicsItem*> mapFeatures;
    GDALDataset* dS;






    // LIPVectorLayer interface
public:
    void setVisible(bool=true) override;
};

#endif // LIPPOINTLAYER_H
