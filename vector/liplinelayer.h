#ifndef LIPLINELAYER_H
#define LIPLINELAYER_H
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include <QString>
#include "lippoint.h"
#include <vector/lipvectorlayer.h>

class LIPLineLayer: public LIPVectorLayer
{
public:
    /**
     * \brief Данный конструктор применяется, если мы создаем новый слой
     */
    LIPLineLayer(OGRLayer *l, QString name);
    /**
     * \brief Данный конструктор применяется, если мы загружаем слой
     */
    LIPLineLayer(QString fileName);
    QString returnGISName();
    QVector<LIPPoint*> returnCords();
private:
    OGRLayer *layer = nullptr;
    QString GISName;
    QVector<LIPPoint*> coordinates;
    QRectF boundingRect;


};

#endif // LIPLINELAYER_H
