#include "lippointlayer.h"

LIPPointLayer::LIPPointLayer(OGRLayer *l, QString name)
    : layer{l},
      GISName(name)
{

}

QString LIPPointLayer::returnGISName()
{
    return GISName;
}
