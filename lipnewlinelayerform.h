#ifndef LIPNEWLINELAYERFORM_H
#define LIPNEWLINELAYERFORM_H

#include <QDialog>

namespace Ui {
class LIPNewLineLayerForm;
}

class LIPNewLineLayerForm : public QDialog
{
    Q_OBJECT

public:
    explicit LIPNewLineLayerForm(QWidget *parent = nullptr);
    ~LIPNewLineLayerForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LIPNewLineLayerForm *ui;
};

#endif // LIPNEWLINELAYERFORM_H
