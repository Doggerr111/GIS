#include "lipproject.h"
#include "QDebug"

LIPProject &LIPProject::getInstance()
{
    static LIPProject instance;
    return instance;
}

void LIPProject::addVectorLayer(LIPVectorLayer *vect)
{
    vectorLayers.append(vect);
}

void LIPProject::addVectorLayers(QVector<LIPVectorLayer *> vects)
{
    for (int i=0; i<vects.size(); i++)
    {
        if (vects.at(i)!=nullptr)
            vectorLayers.append(vects.at(i));
    }
}

void LIPProject::setVectorLayers(QVector<LIPVectorLayer *> vects)
{
    vectorLayers=vects;
}

bool LIPProject::setActiveLayer(LIPVectorLayer *vect)
{
    for (int i=0; i<vectorLayers.size(); i++)
    {
        if (vectorLayers.at(i)==vect)
        {
            activeLayer=vect;
            return true;
        }

    }
    return false;

}

void LIPProject::setActiveLayer(int index)
{
    activeLayer=vectorLayers.at(index);
}

void LIPProject::setActiveLayer(QString name)
{
    for (int i=0; i<vectorLayers.size(); i++)
    {
        if (vectorLayers.at(i)->returnGISName()==name)
        {
            activeLayer=vectorLayers.at(i);
        }
    }
}

QVector<LIPVectorLayer *> LIPProject::getVectorLayers()
{
    return vectorLayers;
}

LIPVectorLayer* LIPProject::getVecorLayerByIndx(int index)
{
    if (vectorLayers.at(index)!=nullptr)
        return vectorLayers.at(index);
    else
    {
        return nullptr;
    }
}

LIPVectorLayer* LIPProject::getVectorLayerByName(QString name)
{
    for (int i=0; i<vectorLayers.size(); i++)
    {
        if (vectorLayers.at(i)->returnGISName()==name)
        {
            return vectorLayers.at(i);
        }
    }
    return nullptr;
}

LIPVectorLayer *LIPProject::getVectorLayerByPath(QString path)
{
    for (int i=0; i<vectorLayers.size(); i++)
    {
        if (vectorLayers.at(i)->returnFileName()==path)
        {
            return vectorLayers.at(i);
        }
        qDebug()<< "VECT:" + QString::number(i);
    }
    return nullptr;
}

LIPVectorLayer* LIPProject::getActiveLayer()
{
    if (activeLayer!=nullptr)
        return activeLayer;
    else
    {
        return nullptr;
    }
}



void LIPProject::redrawNeeded(double f)
{

}
