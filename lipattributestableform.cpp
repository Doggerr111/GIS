#include "lipattributestableform.h"
#include "ui_lipattributestableform.h"

LIPAttributesTableForm::LIPAttributesTableForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LIPAttributesTableForm)
{
    ui->setupUi(this);
}

LIPAttributesTableForm::~LIPAttributesTableForm()
{
    delete ui;
}

void LIPAttributesTableForm::setLayer(LIPVectorLayer *layer)
{
    if (layer!=nullptr)
        ui->tableWidget->setLayer(layer);
}
