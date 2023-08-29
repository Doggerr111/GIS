#ifndef LIPTYPES_H
#define LIPTYPES_H

enum class LIPGeometryType{
    LIPPoint,
    LIPMultiPoint,
    LIPLineString,
    LIPMultiLine
};

enum class LIPStyleUnit{
    Millimeters,
    Inches,
    Pixels
};

class LIPTypes
{
public:
    enum class LIPCrs {};

    enum class LIPDrivers{
        ESRIShapefile
    };

    LIPTypes();
};

#endif // LIPTYPES_H
