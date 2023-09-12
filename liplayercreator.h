#ifndef LIPLAYERCREATOR_H
#define LIPLAYERCREATOR_H
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include "liptypes.h"
#include "QObject"
#include <QVariant>
#include "vector/lippointlayer.h"



class LIPLayerCreator
{
public:
    LIPLayerCreator(LIPGeometryType type, QString filename, QString nameGIS);
    void createAttribute(LIPAttributeType type, QString name);
    void setAttribute(LIPAttributeType type, QVariant attribute, QString name);
    void setName(QString f);
    void setCodec();
    void setGeometry();
    OGRLayer* returnOGRLayer();
    LIPPointLayer* returnLayer();
private:
    char fileName;
    OGRLayer *layer;
    LIPPointLayer* LIPLayer;
    QString mainName;


};

#endif // LIPLAYERCREATOR_H
