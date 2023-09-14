#ifndef LIPVECTORREADER_H
#define LIPVECTORREADER_H

#include <QObject>
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include "QDebug"
#include "liptypes.h"
#include "QMessageBox"
#include "lipvectorlayer.h"
#include "lippointlayer_1.h"
#include "vector/lippointlayer.h"
#include "vector/lippoint.h"

class LIPVectorReader : public QObject
{
    Q_OBJECT
public:
    LIPVectorReader(const LIPTypes::LIPDrivers Driver, const char* new_filename);
    bool Read();
    /**
     *
     * \brief Данная функция считывает координаты векторного слоя
     */
    bool ReadGeometry();
    /**
     *
     * \brief Данная функция возвращает охват слоя
     */
    QRectF ReadBoundingBox();
    LIPPointLayer* returnLayer();
    static OGRLayer *readOGRLayer(QString filename);
    static LIPGeometryType readGeometryType(OGRLayer* layer);
    //bool ReadGeometry():

private:
    const LIPTypes::LIPDrivers driver;
    const char* fileName;
    LIPGeometryType geomertyType;
    LIPPointLayer *layer;
};

#endif // LIPVECTORREADER_H
