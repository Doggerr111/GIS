#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <lipvectorreader.h>
#include <QFileDialog>
#include <lipmapscene.h>
#include <qgraphicsitem.h>
#include <lippointgraphicsitem.h>
#include <qgraphicsscene.h>
#include <QWheelEvent>
#include <QThread>
#include <lipmapcalculations.h>
#include <QDesktopWidget>
#include <QScrollBar>
#include <QScreen>
#include <QGraphicsView>
#include <lipaddingitems.h>
#include <QPainter>
#include <QImage>
#include <QPen>
#include <QMessageBox>
#include <liplayertreeitem.h>
#include <liplayertreemodel.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void scenePos(QPointF p);

    void recalculateScale();

    void changeExtent(QPointF click_pos, QPointF cur_pos);

    QRectF getSceneRect();

    void showContextMenu(QPoint p);

    void test(QPointF p);
    void on_treeView_clicked(const QModelIndex &index);

    void on_pushButton_GeoTiff_clicked();

    void on_pushButton_4_clicked();

    void on_actionNew_line_layer_triggered();

signals:
    void start_add();


private:
    Ui::MainWindow *ui;
    double scale_factor=1;
    QPainter *painter;
    QImage img;
    QPixmap pix;
    QPainter pa;
    QImage img2;
    QVector<LIPPoint*> pVect;

    // QWidget interface
protected:
    void wheelEvent(QWheelEvent *event);
};
#endif // MAINWINDOW_H
