#include "lipvectorlayer.h"
#include "QDebug"
LIPVectorLayer::LIPVectorLayer(OGRLayer *l, QString path, GDALDataset *dataset)
    : layer{l},
      dS{dataset},
      fileName{path}


{

}

QString LIPVectorLayer::returnGISName()
{

}

QString LIPVectorLayer::returnFileName()
{
    return fileName;
}

LIPVectorLayer::~LIPVectorLayer()
{
    mStyle=nullptr;
    delete mStyle;
    dS=nullptr;
    GDALClose(dS);
    layer=nullptr;
    delete layer;
}

void LIPVectorLayer::addFeature(QVector<QPointF> coords, QVector<LIPAttribute> attrs)
{

}

void LIPVectorLayer::setVisible(bool)
{

}
/////////////
std::map<int, QVector<LIPAttribute>> LIPVectorLayer::getAttributes()
{
    return LIPVectorReader::readAttributes(layer);
}

QVector<LIPAttributeType> LIPVectorLayer::getAttributeTypes()
{
    OGRFeatureDefn* featureDefn = layer->GetLayerDefn();
    int attributeCount = featureDefn->GetFieldCount(); // Получение количества атрибутов
    for (int i = 0; i < attributeCount; i++)
    {
        OGRFieldDefn* fieldDefn = featureDefn->GetFieldDefn(i);
        OGRFieldType fieldType = fieldDefn->GetType(); // Получение типа данных
        //qDebug()<<fieldDefn->GetNameRef();
        switch (fieldType)
        {
        case OFTInteger:
            attributeTypes.append(LIPAttributeType::INT32);
            break;
        case OFTReal:
            attributeTypes.append(LIPAttributeType::Real);
            break;
        default:
            attributeTypes.append(LIPAttributeType::String);
            break;
        }
    }
    return attributeTypes;
}

QVector<QString> LIPVectorLayer::getAttributeNames()
{
    attributeNames.clear();
    OGRFeatureDefn* featureDefn = layer->GetLayerDefn();
    int attributeCount = featureDefn->GetFieldCount(); // Получение количества атрибутов
    for (int i = 0; i < attributeCount; i++)
    {
        OGRFieldDefn* fieldDefn = featureDefn->GetFieldDefn(i);
        attributeNames.append(QString::fromUtf8(fieldDefn->GetNameRef())); //получаем название атрибута
    }
    return attributeNames;

}

QStringList LIPVectorLayer::getAttributesNamesAsList()
{
    QStringList list;
    OGRFeatureDefn* featureDefn = layer->GetLayerDefn();
    int attributeCount = featureDefn->GetFieldCount(); // Получение количества атрибутов
    for (int i = 0; i < attributeCount; i++)
    {
        OGRFieldDefn* fieldDefn = featureDefn->GetFieldDefn(i);
        list.append(QString::fromUtf8(fieldDefn->GetNameRef())); //получаем название атрибута
    }
    return list;
}

QRectF LIPVectorLayer::getBoundingBox()
{
    OGREnvelope envelope;
    layer->GetExtent(&envelope, true);
    qreal minX = envelope.MinX;
    qreal minY = envelope.MinY;
    qreal maxX = envelope.MaxX;
    qreal maxY = envelope.MaxY;
    return QRectF(minX, minY, maxX - minX, maxY - minY);
}

QVector<LIPAttribute> LIPVectorLayer::stringValToAttrs(QVector<QString> names, QVector<QString> values, QVector<LIPAttributeType> types)
{
    QVector<LIPAttribute> attributes;
    bool typeFlag=false;
    for (int i=0; i<values.size(); i++)
    {
        if (values.at(i).trimmed().isEmpty())
        {
            LIPAttribute attr(names.at(i),types.at(i), QString());
            attributes.append(attr);

        }
        else
        {
            switch (types.at(i))
            {
            case LIPAttributeType::INT32:
                values.at(i).toInt(&typeFlag);
                if (typeFlag)
                {
                    LIPAttribute attr(names.at(i), types.at(i), values.at(i));
                    attributes.append(attr);
                }
                break;
            case LIPAttributeType::Real:
                values.at(i).toDouble(&typeFlag);
                if (typeFlag)
                {
                    LIPAttribute attr(names.at(i), types.at(i), values.at(i));
                    attributes.append(attr);
                }
                break;
            case LIPAttributeType::String:
                LIPAttribute attr(names.at(i), types.at(i), values.at(i));
                attributes.append(attr);
                typeFlag=true;
                break;
            }
            if (!typeFlag)
            {
                LIPAttribute attr(names.at(i), types.at(i), QString());
                attributes.append(attr);
            }
        }
    }
    return attributes;
}

LIPVectorStyle *LIPVectorLayer::getStyle()
{
    return mStyle;
}

void LIPVectorLayer::setMapFeatures()
{

}

OGRLayer *LIPVectorLayer::getOGRLayer()
{
    return layer;
}

void LIPVectorLayer::setSceneScaleFactor(double factor)
{

}



