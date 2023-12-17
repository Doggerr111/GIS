#include "lipwidgetmanager.h"
#include "QDebug"
#include <QLabel>

LIPWidgetManager &LIPWidgetManager::getInstance()
{
    static LIPWidgetManager instance;
    return instance;
}

void LIPWidgetManager::setMainWindow(QMainWindow *mainWindow)
{
    mMainWindow = mainWindow;
}

void LIPWidgetManager::showMessage(const QString &errorMessage, int msec, messageStatus st)
{
    QGraphicsView* graphicsView = mMainWindow->findChild<QGraphicsView*>("graphicsView");
    if (graphicsView!=nullptr)
    {
        QWidget *errorWidget = new QWidget(graphicsView);
        QVBoxLayout *layout = new QVBoxLayout;
        QPushButton *button = new QPushButton();

        switch (st)
        {
        case Success:
        {
            errorWidget->setStyleSheet("background-color: rgb(3, 218, 198);"
                                       "border: 0px solid black");
        }
        case Neutral:
        {
            errorWidget->setStyleSheet("background-color: rgb(255, 255, 0);"
                                       "border: 0px solid black");
        }
        case Error:
        {
            errorWidget->setStyleSheet("background-color: rgb(0, 255, 0);"
                                       "border: 0px solid black");
        }
        }
        errorWidget->update();


        QPixmap pixmap(":/ui/icons/close.png");
        QIcon buttonIcon(pixmap);
        button->setIcon(buttonIcon);
        //button->setIconSize(pixmap.rect().size());
        layout->setAlignment(Qt::AlignRight);
        layout->setSpacing(0);
        QTextEdit *edit = new QTextEdit(errorMessage);
        layout->addWidget(button,0, Qt::AlignTop | Qt::AlignRight);
        layout->addSpacing(10);
        QSpacerItem *spacer =new QSpacerItem(graphicsView->geometry().width(), 5, QSizePolicy::Minimum, QSizePolicy::Expanding);
        layout->addSpacerItem(spacer);
        layout->addWidget(edit);
        errorWidget->setLayout(layout);
        errorWidget->setGeometry(0,0,graphicsView->geometry().width(),100);
        QVBoxLayout vb;
        errorWidget->show();
        QTimer* timer = new QTimer;
        connect(button, &QPushButton::clicked, [errorWidget, timer](){
            timer->stop();
            delete errorWidget;

        });
        connect(timer, &QTimer::timeout, [errorWidget, timer](){
            //errorWidget->hide();
            timer->stop();
            delete errorWidget;

        });
        timer->setInterval(msec);
        timer->start();



    }
}

QGraphicsScene *LIPWidgetManager::getScene()
{
    QGraphicsView* graphicsView = mMainWindow->findChild<QGraphicsView*>("graphicsView");
    if (graphicsView==nullptr)
        return nullptr;
    return graphicsView->scene();

}


