#include "lipattribute.h"

LIPAttribute::LIPAttribute(QString n, LIPAttributeType t, QVariant v)
    : name{n},
      type{t},
      value{v}
{

}

QString LIPAttribute::getName() const
{
    return name;
}

LIPAttributeType LIPAttribute::getType() const
{
    return type;
}

QVariant LIPAttribute::getValue() const
{
    return value;
}
