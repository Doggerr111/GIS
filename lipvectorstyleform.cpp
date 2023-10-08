#include "lipvectorstyleform.h"
#include "ui_lipvectorstyleform.h"

LIPVectorStyleForm::LIPVectorStyleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LIPVectorStyleForm)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->setSceneRect(0,0,50,50);
}

LIPVectorStyleForm::~LIPVectorStyleForm()
{
    delete ui;
}

void LIPVectorStyleForm::on_pushButtonPointColor_clicked()
{
    QColorDialog *pointColorDialog = new QColorDialog(this);
    pointColorDialog->exec();
    QColor pointColor = pointColorDialog->getColor();
    if (pointColor.isValid())
    {
        pen.setColor(pointColor);
        ui->pushButtonPointColor->setStyleSheet("background-color: " + pointColor.name() + ";");
    }
    QGraphicsEllipseItem *item = new QGraphicsEllipseItem;

    item->setRect(25-LIPVectorStyle::MMToPixel(ui->lineEditPointSize->text().toDouble()/2),
                  25-LIPVectorStyle::MMToPixel(ui->lineEditPointSize->text().toDouble()/2),
                  LIPVectorStyle::MMToPixel(ui->lineEditPointSize->text().toDouble()),
                  LIPVectorStyle::MMToPixel(ui->lineEditPointSize->text().toDouble()));
    item->setPen(pen);
    //item->setPos(25,25);
    ui->graphicsView->scene()->addItem(item);

}

