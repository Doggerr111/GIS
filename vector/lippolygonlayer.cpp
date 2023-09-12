#include "lippolygonlayer.h"

LIPPolygonLayer::LIPPolygonLayer(OGRLayer *l, QString name)
    : layer{l},
      GISName(name)
{

}

QString LIPPolygonLayer::returnGISName()
{
    return GISName;
}
