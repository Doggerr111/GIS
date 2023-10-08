#ifndef LIPVECTORLAYER_H
#define LIPVECTORLAYER_H
#include <qstring.h>
#include <QObject>
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include "liptypes.h"
#include "lipattribute.h"
class LIPVectorLayer
{
public:
    LIPVectorLayer(OGRLayer *l, QString path, GDALDataset *dataset);
    virtual QString returnGISName();
    QString returnFileName();
    virtual ~LIPVectorLayer();
    virtual void addFeature(QVector<QPointF> coords, QVector<LIPAttribute> attrs);
    QVector<LIPAttributeType> getAttributeTypes();
    QVector<QString> getAttributeNames();
    static QVector<LIPAttribute> stringValToAttrs(QVector<QString> names, QVector<QString> values, QVector<LIPAttributeType> types);
protected:
    OGRLayer *layer;
    GDALDataset *dS;
    QString fileName;
    QVector<LIPAttributeType> attributeTypes;
    QVector<QString> attributeNames;

signals:
    void needRepaint();



};

#endif // LIPVECTORLAYER_H
