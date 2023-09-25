#include "lipproject.h"

LIPProject::LIPProject()
{

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

void LIPProject::setActiveLayer(LIPVectorLayer *vect)
{
    activeLayer=vect;
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

LIPVectorLayer* LIPProject::getActiveLayer()
{
    if (activeLayer!=nullptr)
        return activeLayer;
    else
    {
        return nullptr;
    }
}
