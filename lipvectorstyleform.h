#ifndef LIPVECTORSTYLEFORM_H
#define LIPVECTORSTYLEFORM_H

#include <QWidget>


namespace Ui {
class LIPVectorStyleForm;
}

class LIPVectorStyleForm : public QWidget
{
    Q_OBJECT

public:
    explicit LIPVectorStyleForm(QWidget *parent = nullptr);
    ~LIPVectorStyleForm();

private:
    Ui::LIPVectorStyleForm *ui;
};

#endif // LIPVECTORSTYLEFORM_H
