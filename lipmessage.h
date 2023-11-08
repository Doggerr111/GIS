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
class LIPMessage: public QObject
{
    Q_OBJECT
public:
    static LIPMessage &getInstance();

    void setMainWindow(QMainWindow* mainWindow);

    void showMessage(const QString& errorMessage, int msec, messageStatus st);

private:
    LIPMessage() = default;
    ~LIPMessage() = default;
    LIPMessage(const LIPMessage&) = delete;
    LIPMessage& operator=(const LIPMessage&) = delete;

    QMainWindow* mMainWindow = nullptr;
};

#endif // LIPMESSAGE_H
