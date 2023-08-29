#include "lipnewlinelayerform.h"
#include "ui_lipnewlinelayerform.h"

LIPNewLineLayerForm::LIPNewLineLayerForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LIPNewLineLayerForm)
{
    ui->setupUi(this);
}

LIPNewLineLayerForm::~LIPNewLineLayerForm()
{
    delete ui;
}

void LIPNewLineLayerForm::on_pushButton_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

