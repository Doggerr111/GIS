#ifndef LIPATTRIBUTESTABLEFORM_H
#define LIPATTRIBUTESTABLEFORM_H

#include <QDialog>
#include "lipvectorlayer.h"

namespace Ui {
class LIPAttributesTableForm;
}

class LIPAttributesTableForm : public QDialog
{
    Q_OBJECT

public:
    explicit LIPAttributesTableForm(QWidget *parent = nullptr);
    ~LIPAttributesTableForm();
    void setLayer(LIPVectorLayer* layer);

private:
    Ui::LIPAttributesTableForm *ui;
};

#endif // LIPATTRIBUTESTABLEFORM_H
