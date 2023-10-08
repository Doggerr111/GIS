#ifndef LIPVECTORSTYLEFORM_H
#define LIPVECTORSTYLEFORM_H

#include <QWidget>
#include <QColorDialog>
#include <QPen>
#include <QBrush>
#include "vector/lippointgraphicsitem.h"
#include "vector/liplinegraphicsitem.h"
#include "vector/lippolygongraphicsitem.h"

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include "vector/lipvectorstyle.h"
namespace Ui {
class LIPVectorStyleForm;
}

class LIPVectorStyleForm : public QWidget
{
    Q_OBJECT

public:
    explicit LIPVectorStyleForm(QWidget *parent = nullptr);
    ~LIPVectorStyleForm();

private slots:
    void on_pushButtonPointColor_clicked();

private:
    QPen pen;
    QBrush brush;

    LIPPointGraphicsItem pointItem;
    LIPPolygonGraphicsItem polyIyem;
    LIPLineGraphicsItem lineItem;
    Ui::LIPVectorStyleForm *ui;

};

#endif // LIPVECTORSTYLEFORM_H
