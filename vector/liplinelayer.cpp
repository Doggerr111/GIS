#include "liplinelayer.h"

LIPLineLayer::LIPLineLayer(OGRLayer *l, QString name)
    : layer{l},
      GISName(name)
{

}

QString LIPLineLayer::returnGISName()
{
    return GISName;
}
