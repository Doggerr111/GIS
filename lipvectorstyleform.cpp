#include "lipvectorstyleform.h"
#include "ui_lipvectorstyleform.h"

LIPVectorStyleForm::LIPVectorStyleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LIPVectorStyleForm)
{
    ui->setupUi(this);
}

LIPVectorStyleForm::~LIPVectorStyleForm()
{
    delete ui;
}
