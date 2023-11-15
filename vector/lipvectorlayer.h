#ifndef LIPVECTORLAYER_H
#define LIPVECTORLAYER_H
#include <qstring.h>
#include <QObject>
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include "liptypes.h"
//#include "lipattribute.h"
#include "lipattribute.h"
#include "lipvectorstyle.h"
#include "lipvectorreader.h"

class LIPVectorLayer: public QObject
{
    Q_OBJECT
public:
    LIPVectorLayer(OGRLayer *l, QString path, GDALDataset *dataset);
    virtual QString returnGISName();
    QString returnFileName();
    virtual ~LIPVectorLayer();
    virtual void addFeature(QVector<QPointF> coords, QVector<LIPAttribute> attrs);
    virtual void setVisible(bool=true);
    QVector<LIPAttributeType> getAttributeTypes();
    QVector<QString> getAttributeNames();
    QStringList getAttributesNamesAsList();
    QRectF getBoundingBox();
    static QVector<LIPAttribute> stringValToAttrs(QVector<QString> names, QVector<QString> values, QVector<LIPAttributeType> types);
    LIPVectorStyle *getStyle();
    virtual void setMapFeatures();
    OGRLayer *getOGRLayer();
    std::map<int, QVector<LIPAttribute>> getAttributes();


protected:
    OGRLayer *layer;
    GDALDataset *dS;
    QString fileName;
    QVector<LIPAttributeType> attributeTypes;
    QVector<QString> attributeNames;
    double mScaleFactor;
    LIPVectorStyle *mStyle;

signals:
    void needRepaint();

public slots:
    virtual void setSceneScaleFactor(double factor);



};

#endif // LIPVECTORLAYER_H
