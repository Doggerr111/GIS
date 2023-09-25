#ifndef LIPATTRIBUTE_H
#define LIPATTRIBUTE_H
#include "liptypes.h"
#include <QVariant>
class LIPAttribute
{
public:
    LIPAttribute();
private:
    LIPAttributeType type;
    QVariant value;
};

#endif // LIPATTRIBUTE_H
