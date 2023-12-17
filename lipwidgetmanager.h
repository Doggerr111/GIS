#ifndef LIPMESSAGE_H
#define LIPMESSAGE_H
#include <QMainWindow>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QTimer>
#include <QObject>
#include <QPushButton>
#include <QTextEdit>
enum messageStatus{
    Success,
    Neutral,
    Error
};

//singleton pattern
class LIPWidgetManager: public QObject
{
    Q_OBJECT
public:
    static LIPWidgetManager &getInstance();

    void setMainWindow(QMainWindow* mainWindow);

    void showMessage(const QString& errorMessage, int msec, messageStatus st);

    QGraphicsScene *getScene();

private:
    LIPWidgetManager() = default;
    ~LIPWidgetManager() = default;
    LIPWidgetManager(const LIPWidgetManager&) = delete;
    LIPWidgetManager& operator=(const LIPWidgetManager&) = delete;

    QMainWindow* mMainWindow = nullptr;
};

#endif // LIPMESSAGE_H
