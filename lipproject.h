#ifndef LIPPROJECT_H
#define LIPPROJECT_H
#include <QObject>
#include <vector/lipvectorlayer.h>
class LIPProject : public QObject
{
    Q_OBJECT
public:
    LIPProject();
    void addVectorLayer(LIPVectorLayer* vect);
    void addVectorLayers(QVector<LIPVectorLayer*> vects);
    void setVectorLayers(QVector<LIPVectorLayer*> vects);
    bool setActiveLayer(LIPVectorLayer* vect);
    void setActiveLayer(int index);
    void setActiveLayer(QString name);

    QVector<LIPVectorLayer*> getVectorLayers();
    LIPVectorLayer* getVecorLayerByIndx(int index);
    LIPVectorLayer* getVectorLayerByName(QString name);
    LIPVectorLayer* getVectorLayerByPath(QString path);
    LIPVectorLayer* getActiveLayer();

public slots:
    void redrawNeeded(double);
private:
    LIPVectorLayer* activeLayer; //
    QVector<LIPVectorLayer*> vectorLayers;

};

#endif // LIPPROJECT_H
