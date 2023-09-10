#ifndef LIPLAYERCREATOR_H
#define LIPLAYERCREATOR_H
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include "liptypes.h"
#include "QObject"


class LIPLayerCreator
{
public:
    LIPLayerCreator(LIPGeometryType type, QString filename);
    void setAttribute();
    void setName(QString f);
    void setCodec();
    void setGeometry();
private:
    char fileName;
    OGRLayer *layer;


};

#endif // LIPLAYERCREATOR_H
