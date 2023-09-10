#include "lipnewlinelayerform.h"
#include "ui_lipnewlinelayerform.h"

LIPNewLineLayerForm::LIPNewLineLayerForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LIPNewLineLayerForm)
{
    ui->setupUi(this);
    QComboBox *typeBox = new QComboBox();
    typeBox->addItem("Int32");
    typeBox->addItem("Real");
    typeBox->addItem("String");
    ui->tableWidget->setCellWidget(0,1,typeBox);
}

LIPNewLineLayerForm::~LIPNewLineLayerForm()
{
    delete ui;
}

void LIPNewLineLayerForm::on_pushButton_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    QComboBox *typeBox = new QComboBox();
    typeBox->addItem("Int32");
    typeBox->addItem("Real");
    typeBox->addItem("String");
    ui->tableWidget->setCellWidget(ui->tableWidget->rowCount()-1,1,typeBox);
}

