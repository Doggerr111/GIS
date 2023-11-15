#ifndef LIPVECTORCONVERTOR_H
#define LIPVECTORCONVERTOR_H

#include <geos/geom/Coordinate.h>
#include <geos/geom/GeometryFactory.h>
#include <geos/geom/Point.h>
#include <geos/geom/Geometry.h>
#include <geos/geom/Envelope.h>
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include "QPointF"
#include "geos/geom/Point.h"

/** Данный класс используется для конвертации объектов GDAL в GEOS и наборот, а также для конвертации в Qt и LIP*/
class LIPVectorConvertor
{
public:
    LIPVectorConvertor();
    //static geos::geom::Point QPointFtoGeosPoint(QPointF qtPoint);
//    static geos::geom::Point *QPointFtoGeosPoint(QPointF* qtPoint);
//    static QPointF geosPointtoQPointF(geos::geom::Point geosPoint);
//    static QPointF* geosPointtoQPointF(geos::geom::Point* geosPoint);
//    //for set of points
//    static QVector<geos::geom::Point> QPointsFtoGeosPoints(QVector<QPointF> qtPoints);
};

#endif // LIPVECTORCONVERTOR_H
