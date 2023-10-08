#ifndef LIPATTRIBUTE_H
#define LIPATTRIBUTE_H
#include "liptypes.h"
#include <QVariant>
class LIPAttribute
{
public:
    LIPAttribute(QString n, LIPAttributeType t, QVariant v);
    QString getName() const;
    LIPAttributeType getType() const;
    QVariant getValue() const;
private:
    QString name;
    LIPAttributeType type;
    QVariant value;



};

#endif // LIPATTRIBUTE_H
