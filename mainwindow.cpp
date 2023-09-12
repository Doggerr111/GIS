#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gdal.h"
#include "gdal_priv.h"
#include "ogrsf_frmts.h"
#include "QDebug"
#include <gdalwarper.h>
#include "lipnewlinelayerform.h"
#include <QOpenGLWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    img2 = QImage(QSize(ui->graphicsView->viewport()->width(),ui->graphicsView->viewport()->height()), QImage::Format_ARGB32_Premultiplied);

    //    img2.setDotsPerMeterX(300);
    //    img2.setDotsPerMeterY(300);
    img2.fill( 0 );
    if (pa.begin( &img2 ))
    {
        QMessageBox::warning(this,"all good","all good");
    }
    pa.setRenderHint( QPainter::Antialiasing, true );

    connect(ui->graphicsView,SIGNAL(MapHolderResized()),this,SLOT(recalculateScale()));
    //    img.setDotsPerMeterX(200);
    //    img.setDotsPerMeterY(200);
    pix=QPixmap(300,300);
    img=QImage(QSize(40000,30000),QImage::Format_RGB32);
    QPen pen1;
    pen1.setWidth(1);
    pen1.setColor(Qt::yellow);

    painter=new QPainter(&pix);
    painter->setPen(pen1);
    LIPMapScene *scene= new LIPMapScene();
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsView->setViewport(new QOpenGLWidget);

    LIPMapScene *calculationScene = new LIPMapScene();
    connect(scene,SIGNAL(pos_changed(QPointF)),this,SLOT(scenePos(QPointF)));
    connect(scene,SIGNAL(scene_dragging(QPointF,QPointF)),this,SLOT(changeExtent(QPointF,QPointF)));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setTransformationAnchor( QGraphicsView::AnchorUnderMouse );
    //ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    ui->graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    ui->graphicsView->setAttribute(Qt::WA_OpaquePaintEvent);
    ui->graphicsView->setAttribute(Qt::WA_NoSystemBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);

    layerModel = new LIPObjectTreeModel(this);
    QStringList cols;
    cols << "objectName";
    layerModel->setColumns(cols);
    QObject* item1 = new QObject();
    item1->setObjectName("Father");
//    QObject* item2 = new QObject(item1);
//    item2->setProperty("objectName", "Son");
    layerModel->addItem(item1, QModelIndex());
    ui->treeView->setModel(layerModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //Writing
    GDALAllRegister();
    const char *shpFileName = "/home/doger/Downloads/ASM_adm/ASM_adm3.shp";
    const char *driverName = "ESRI Shapefile";
    GDALDriver *driver = GetGDALDriverManager()->GetDriverByName(driverName); //getting a driver
    GDALDataset *dataset = driver->Create(shpFileName, 0,0,0, GDT_Unknown, NULL);
    OGRLayer *layer = dataset->CreateLayer("ring", NULL, wkbMultiLineString, NULL);




}


void MainWindow::on_pushButton_2_clicked()
{
    //reading shp!)
    QString fileName=QFileDialog::getOpenFileName(this,"","");
    QFile file(fileName);
    if (file.open(QFile::ReadWrite))
    {
        //QMessageBox::information(this,"","Open!");
    }
    OGRRegisterAll();
    QByteArray bytea=fileName.toLocal8Bit();
    const char *charname=bytea.data();
    GDALDataset *poDS = (GDALDataset *)GDALOpenEx(charname, GDAL_OF_READONLY, NULL, NULL, NULL);
    if (poDS == NULL)
    {
        qDebug()<<"Open failed.\n";
        return;
    }

    OGRLayer *poLayer = poDS->GetLayer(0);

    OGRFeature *poFeature;

    poLayer->ResetReading();
    //ui->textEdit->append(QString::number(poLayer->GetSpatialRef()->GetEPSGGeogCS()));
    while ((poFeature = poLayer->GetNextFeature()) != NULL)
    {
        OGRFeatureDefn *poFDefn = poLayer->GetLayerDefn();
        int iField;


        for (iField = 0; iField < poFDefn->GetFieldCount(); iField++)
        {
            OGRFieldDefn *poFieldDefn = poFDefn->GetFieldDefn(iField);
            if (poFieldDefn->GetType() == OFTInteger)
                qDebug()<<"%d, " +  QString::number(poFeature->GetFieldAsInteger(iField));
            else if (poFieldDefn->GetType() == OFTInteger64)
                qDebug()<<"%lld, "+QString::number( poFeature->GetFieldAsInteger64(iField));
            else if (poFieldDefn->GetType() == OFTReal)
                qDebug()<<"%.3f, "+QString::number(poFeature->GetFieldAsDouble(iField));
            else if (poFieldDefn->GetType() == OFTString)
                qDebug()<<"%s, " + QString(poFeature->GetFieldAsString(iField));
            else
                qDebug()<<"%s, " + QString(poFeature->GetFieldAsString(iField));
        }
        qDebug()<<("\n");

        OGRGeometry *poGeometry = poFeature->GetGeometryRef();

        if (poGeometry != NULL)
        {
            switch (poGeometry->getGeometryType())
            {
            case wkbLineString:
            {
                OGRLineString *line = (OGRLineString *)poGeometry;
                for (int i = 0; i < line->getNumPoints(); i++)
                {
                    qDebug()<<"wkbLineString %d: x=%g y=%g z=%g\n", i, line->getX(i), line->getY(i), line->getZ(i);
                }
                break;
            }
            case wkbPolygon:
            {
                OGRPolygon *poly = (OGRPolygon *)poGeometry;
                OGRLinearRing *ring = (OGRLinearRing *)poly->getExteriorRingCurve();
                for (int i = 0; i < ring->getNumPoints(); i++)
                {
                    qDebug()<<"wkbPolygon %d: x=%g y=%g z=%g\n" +QString::number(i) + QString::number( ring->getX(i)), ring->getY(i), ring->getZ(i);
                }
                break;
            }
            case wkbMultiLineString:
            {
                OGRMultiLineString *multiLine = (OGRMultiLineString *)poGeometry;
                for (int n = 0; n < multiLine->getNumGeometries(); n++)
                {
                    OGRLineString *line = (OGRLineString *)multiLine->getGeometryRef(n);
                    for (int i = 0; i < line->getNumPoints(); i++)
                    {
                        qDebug()<<"wkbMultiLineString %d-%d: x=%g y=%g z=%g\n", n, i, line->getX(i), line->getY(i), line->getZ(i);
                    }
                }

                break;
            }
            default:
                qDebug()<<"no point geometry\n";
                break;
            }
        }

        OGRFeature::DestroyFeature(poFeature);
    }

    GDALClose(poDS);
}


void MainWindow::on_pushButton_3_clicked()
{
    //    LIPMapScene *scene= new LIPMapScene();
    //    LIPMapScene *calculationScene = new LIPMapScene();
    //    connect(scene,SIGNAL(pos_changed(QPointF)),this,SLOT(scenePos(QPointF)));
    //    connect(scene,SIGNAL(scene_dragging(QPointF,QPointF)),this,SLOT(changeExtent(QPointF,QPointF)));
    //    ui->graphicsView->setScene(scene);
    //    ui->graphicsView->setTransformationAnchor( QGraphicsView::AnchorUnderMouse );
    //    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);

    QString fileName=QFileDialog::getOpenFileName(this,"","");
    QByteArray bytea=fileName.toLocal8Bit();
    const char *charname=bytea.data();

    LIPVectorReader reader(LIPTypes::LIPDrivers::ESRIShapefile, charname);
    //reader.moveToThread(thread);


    reader.ReadGeometry();
    ui->graphicsView->scene()->setSceneRect(-180,90,360,-180);

    //scene->setSceneRect(-98292019,89852960,704459722-98292019, -453620743-89852960);
    //ui->graphicsView->fitInView(-180,90,360,-180);
    ui->graphicsView->setScene(ui->graphicsView->scene());
    ui->graphicsView->scale(1,-1);

    LIPPointLayer *l=reader.returnLayer();

    QRectF rect=reader.ReadBoundingBox();
    QVector<QGraphicsItem*> items;
    //LIPPointLayer *layer = new LIPPointLayer;
    QPainter *painter=new QPainter(ui->graphicsView);
    LIPLayerTreeModel *model=new LIPLayerTreeModel();
    ui->treeView->setModel(model);
    QStringList cols;
    cols << "2" << "1";
    model->setColumns(cols);
    QObject* item1 = new QObject();
    item1->setObjectName("Point Layer");
    item1->setProperty("x", "d");
    model->addItem(item1,QModelIndex());
    QObject* item2 = new QObject();
    item2->setObjectName("Point Layer");
    item2->setProperty("2","Vector layer 1");
//    for (int i=0;i<l->struct_size();i++)
//    {
//        //layer->addPoint(l->pointAt(i));
//        l->pointAt(i)->draw(painter);
//        QList<QVariant> list;
//        pVect.append(l->pointAt(i));
//        list.append(l->pointAt(i)->x());
//        list.append(l->pointAt(i)->y());
//        LIPLayerTreeItem item(list);
//        //test(QPointF(l->pointAt(i)->x(),l->pointAt(i)->y()));

//        //break;
//        //        QObject* item1 = new QObject();
//        //        item1->setObjectName("Point Layer");
//        //        item1->setProperty("2", l->pointAt(i)->x());

//        //        //Item2 (parent: item1)
//        //        QObject* item2 = new QObject(item1);
//        //        item2->setObjectName("Point");
//        //        item2->setProperty("1", l->pointAt(i)->y());

//        model->addItem(item1, ui->treeView->currentIndex());
//        model->addItem(item2, ui->treeView->currentIndex());


//        LIPPointGraphicsItem * itemp = new LIPPointGraphicsItem;

//        QGraphicsEllipseItem *el=new QGraphicsEllipseItem;
////        el->setFlag(QGraphicsItem::ItemIsMovable,false);
////        el->setFlag(QGraphicsItem::ItemIsSelectable, false);
////        el->setFlag(QGraphicsItem::ItemIsFocusable, false);
////        el->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
////        el->setRect(l->pointAt(i)->x(),l->pointAt(i)->y(),3.77*5,3.77*5);
////        itemp->setPoint(l->pointAt(i));
////        itemp->setBoundingRect(rect);
////        QPen pen;

//        //pen.setWidthF(0.05);

//        //el->setPen(pen);
//        el->setBrush(Qt::blue);

//        ui->graphicsView->scene()->addItem(el);
//        //scene->addItem(el);



//        //scene->addItem(item);
//        //item->setPos(l->pointAt(i)->x(),l->pointAt(i)->y());
//        //        qDebug()<<l->pointAt(i);

//    }
    QPixmap rendered(ui->graphicsView->viewport()->rect().width(),ui->graphicsView->viewport()->rect().height());  // Create the image with the exact size of the shrunk scene
    rendered.fill(Qt::transparent);
    QPainter *paintr = new QPainter(&rendered);
    //calculationScene->render(paintr);
    rendered.save("/home/doger/Pictures/abf1.png");
    ui->graphicsView->scene()->addPixmap(rendered);

    //ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(img2));
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pix);
    //scene->addItem(item);
    item->setPos(0,0);
    item->show();
    ui->graphicsView->scene()->update();
    //scene->addItem(layer);
    LIPAddingItems *add=new LIPAddingItems(ui->graphicsView->scene(),items);
    connect(this, SIGNAL(start_add()),add,SLOT(start()));
    QThread *thread1 = new QThread();
    //thread1->start();
    //add->moveToThread(thread1);
    //thread1->start(); //getting errors but work ok
    emit start_add();

    //ui->graphicsView->fitInView(43,56,3,3);

    fileName=QFileDialog::getOpenFileName(this,"","");
    bytea=fileName.toLocal8Bit();
    charname=bytea.data();

    GDALDataset* dataset = (GDALDataset*) GDALOpen(charname, GA_ReadOnly);
    if (dataset == NULL) {
        // Обработка ошибки открытия файла
    }

    // Получение информации о размере изображения
    int width = dataset->GetRasterXSize();
    int height = dataset->GetRasterYSize();

    double geoTransform[6];
    dataset->GetGeoTransform(geoTransform);

    const char* targetProjection = "EPSG:4326";
    const char* resamplingMethod = "bilinear";

    // Создание объекта gdalwarp

    GDALWarpOptions* warpOptions = GDALCreateWarpOptions();
    warpOptions->hSrcDS = dataset;
    warpOptions->hDstDS = NULL;
    warpOptions->nBandCount = 1;
    warpOptions->panSrcBands = (int*) CPLMalloc(sizeof(int));
    warpOptions->panSrcBands[0] = 1;
    warpOptions->panDstBands = (int*) CPLMalloc(sizeof(int));
    warpOptions->panDstBands[0] = 1;
    warpOptions->papszWarpOptions = CSLDuplicate(NULL);
    CSLAddString(warpOptions->papszWarpOptions, "-overwrite");
    warpOptions->papszWarpOptions = CSLSetNameValue(warpOptions->papszWarpOptions,
                                                    "SRC_SRS", dataset->GetProjectionRef());
    warpOptions->papszWarpOptions = CSLSetNameValue(warpOptions->papszWarpOptions,
                                                    "DST_SRS", targetProjection);
    warpOptions->papszWarpOptions = CSLSetNameValue(warpOptions->papszWarpOptions,
                                                    "RESAMPLING", resamplingMethod);

    // Создание нового GeoTIFF-файла с перепроектированным растровым изображением
    dataset= (GDALDataset*) GDALAutoCreateWarpedVRT(dataset, dataset->GetProjectionRef(),
                                                    targetProjection, GRA_Bilinear, 0.0, NULL);
    // Установка координатных системы

    //ui->graphicsView->setTransform(transform);

    // Чтение данных изображения
    GDALRasterBand* rasterBand = dataset->GetRasterBand(1);
    std::vector<uint16_t> data(width * height);
    rasterBand->RasterIO(GF_Read, 0, 0, width, height, &data[0], width, height, GDT_UInt16, 0, 0);


    // Создание графической сцены и добавление элементов

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uint16_t pixelValue = data[y * width + x];
            // Создание элемента QGraphicsRectItem с цветом, соответствующим значению пикселя
            QColor color(pixelValue >> 8, pixelValue & 0xFF, 0);
            QGraphicsRectItem* item = new QGraphicsRectItem(x, y, 1, 1);
            item->setBrush(QBrush(color));
            //ui->graphicsView->scene()->addItem(item);
        }
    }

    // Создание и настройка виджета QGraphicsView


    // Отображение виджета
    //view.show();

    // Освобождение памяти
    GDALClose(dataset);


}

void MainWindow::scenePos(QPointF p)
{
    ui->lineEdit->setText(QString::number(p.x()) + " "+QString::number(p.y()));
    //ui->graphicsView->centerOn(p);
}

void MainWindow::recalculateScale()
{
    LIPMapCalculations *calculator = new LIPMapCalculations();
    calculator->setDpi(QGuiApplication::primaryScreen()->logicalDotsPerInch());
    QMatrix const matrix = ui->graphicsView->matrix().inverted();

    QRect visibleRect = matrix.mapRect(ui->graphicsView->viewport()->rect());
    visibleRect.moveTopLeft(matrix.map(QPoint(ui->graphicsView->horizontalScrollBar()->value(),
                                              ui->graphicsView->verticalScrollBar()->value())));
    qDebug()<<visibleRect.width();
    double scale = calculator->calculate(visibleRect, ui->graphicsView->width());
    ui->lineEdit_2->setText(QString::number(static_cast<int>(scale)));
    qDebug()<<"map scale is "+ QString::number(scale);
    delete calculator;
}

void MainWindow::changeExtent(QPointF clickPos, QPointF curPos)
{
    //    QMatrix const matrix = ui->graphicsView->matrix().inverted();
    //    QRectF visibleRect = matrix.mapRect(ui->graphicsView->viewport()->rect());
    //    visibleRect.moveTopLeft(matrix.map(QPointF(ui->graphicsView->horizontalScrollBar()->value(),
    //                                            ui->graphicsView->verticalScrollBar()->value())));
    QRectF visibleRect=getSceneRect();
    double x=-(visibleRect.x()+curPos.x()-clickPos.x());
    double y=visibleRect.y()+curPos.y()-clickPos.y();
    QRectF rect(x,y,visibleRect.width(),visibleRect.height());
    qDebug()<<clickPos;
    qDebug()<<curPos;
    qDebug()<<QString::number(rect.x())+" "+QString::number(rect.y())+" "+QString::number(rect.width())+" "+QString::number(rect.height());
    //ui->textEdit->append(QString::number(rect.x())+" "+QString::number(rect.y())+" "+QString::number(rect.width())+" "+QString::number(rect.height()));

    //ui->graphicsView->scale(1,-1);
    //    QRectF G=ui->graphicsView->mapToScene(ui->graphicsView->rect()).boundingRect();
    //    qDebug()<<G.width();


    //ui->graphicsView->fitInView(rect);
    //ui->graphicsView->setSceneRect(rect);
    //ui->graphicsView->setSceneRect(rect);
    //ui->graphicsView->centerOn(ui->graphicsView->mapFromScene(pos.toPoint()));
}

QRectF MainWindow::getSceneRect()
{
    return ui->graphicsView->mapToScene(ui->graphicsView->rect()).boundingRect();
}

void MainWindow::showContextMenu(QPoint p)
{
    QPoint globalPos;
    // если запрос от QAbstractScrollArea
    if (sender()->inherits("QTreeView"))
        globalPos = (qobject_cast<QTreeView*>(sender())->viewport()->mapToGlobal(p));
    // если от других виджетов
    else
        globalPos = ui->treeView->mapToGlobal(p);

    QMenu menu;
    // Создаем пункт меню
    QAction* action1 = new QAction(QString::fromUtf8("Пункт 1"), this);
    // добавляем пункт в меню
    menu.addAction(action1);
    // добавляем разделитель
    menu.addSeparator();
    // добавляем еще один пункт меню
    QAction* action2 = new QAction(QString::fromUtf8("Пункт 2"), this);
    menu.addAction(action2);
    menu.show();
    menu.exec(globalPos);
}

void MainWindow::test(QPointF point)
{
    const int dot_per_millimeter = qRound(qApp->primaryScreen()->physicalDotsPerInch() / 25.40);
    QPen mPen;
    QBrush mBrush;
    mBrush.setColor(Qt::blue);
    mBrush.setStyle(Qt::SolidPattern);
    mPen.setWidthF(1.0);
    mPen.setColor(Qt::blue);
    double scaledSize = 4.0;

    // calculate necessary image size for the cache
    double pw = (( mPen.widthF() == 0 ? 1 : mPen.widthF() ) + 1 ) / 2 * 2; // make even (round up); handle cosmetic pen
    int imageSize = (( int ) scaledSize + pw ) / 2 * 2 + 1; //  make image width, height odd; account for pen width

    double center = (( double ) imageSize / 2 ) + 0.5; // add 1/2 pixel for proper rounding when the figure's coordinates are added

    QImage mCache = QImage( QSize( 30, 30 ), QImage::Format_ARGB32_Premultiplied );
    mCache.fill( 0 );
    double sdg=mCache.devicePixelRatio();
    //mCache.setDevicePixelRatio(200);
    QPainter p;
    p.begin( &mCache );
    p.setRenderHint( QPainter::Antialiasing );
    p.setBrush( mBrush );




    //p.translate( QPointF( center, center ) );

    int dpm = 1000 / 0.0254; // ~300 DPI
    //кол-во точек в 1 мм
    //mPen.setWidthF(mm * 10); //
    p.setPen(5);
    mCache.setDotsPerMeterX(dpm);
    mCache.setDotsPerMeterY(dpm);
    qDebug()<<mCache.physicalDpiX();


    //допустим 10 милиметров


    //pixel to mm
    const int dots_per_millimeter = qRound(qApp->primaryScreen()->physicalDotsPerInch() / 25.40);

    p.drawEllipse(QRectF(0,0,3.77*5,3.77*5));
    //    if (mCache.save("/home/doger/Pictures/abf.png"))
    //    {
    //        QMessageBox::warning(this,"","");
    //    }

    pa.drawImage(QPointF(point.x()-mCache.width()/2,point.y()-mCache.height()/2),mCache);

    ui->graphicsView->scene()->update();


    // Construct the selected version of the Cache




    // Check that the selected version is different.  If not, then re-render,
    // filling the background with the selection color and using the normal
    // colors for the symbol .. could be ugly!





}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y()<0 )
    {
        scale_factor=0.3;

        ui->graphicsView->scale(scale_factor, scale_factor);
    }
    else if (event->angleDelta().y()>0) {
        scale_factor=2;
        ui->graphicsView->scale(scale_factor, scale_factor);
    }
    //ui->graphicsView->setSceneRect(0,0,12,12);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graphicsView->setResizeAnchor(QGraphicsView::AnchorViewCenter );

    recalculateScale();
    qDebug()<<ui->graphicsView->transform().m11();
    //ui->graphicsView->setFocusPolicy( Qt::NoFocus );
    //        ui->graphicsView->scene()->clear();
    //        pa.end();
    ui->graphicsView->scene()->clear();

    for (int i=0; i<pVect.size(); i++)
    {
        LIPPoint *l=new LIPPoint;
        l=pVect.at(i);
        //ui->graphicsView->setInteractive(false);
        QGraphicsEllipseItem *el=new QGraphicsEllipseItem;
        int scaleF=ui->graphicsView->transform().m11();
        el->setFlag(QGraphicsItem::ItemIsMovable,false);
        el->setFlag(QGraphicsItem::ItemIsSelectable, false);
        el->setFlag(QGraphicsItem::ItemIsFocusable, false);
        el->setFlag(QGraphicsItem::ItemClipsToShape, false);
        el->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
        el->setRect(l->x(),l->y(),3.77*5/scaleF,3.77*5/scaleF);

        QPen pen;

        pen.setWidthF(0);

        el->setPen(pen);
        el->setBrush(Qt::blue);

        ui->graphicsView->scene()->addItem(el);
    }
    QTransform tr(1, 0, 0, 1, 50.0, 50.0);
    QMatrix const matrix = ui->graphicsView->matrix().inverted();
    QRect visibleRect = matrix.mapRect(ui->graphicsView->viewport()->rect());

    //        img2 = QImage(QSize(visibleRect.width(),visibleRect.height()), QImage::Format_ARGB32_Premultiplied);
    //        pa.begin(&img2);
    //        //pa.setViewport(visibleRect);
    //        for(int i=0;i<pVect.size();i++)
    //        {
    //            test(QPointF(pVect.at(i)->x(),pVect.at(i)->y()));

    //        }
    //        ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(img2));
}

//void MainWindow::paintEvent(QPaintEvent *event)
//{

//        if (m_frameCount == 0) {
//             m_time.start();
//        } else {
//            printf("FPS is %f ms\n", m_time.elapsed() / float(m_frameCount));
//        }
//        m_frameCount++;

//        // Painting goes here...




//}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    QMessageBox::information(this,"",QString::number(index.row()));
    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->treeView, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(showContextMenu(QPoint)));
}


void MainWindow::on_pushButton_GeoTiff_clicked()
{


}


void MainWindow::on_pushButton_4_clicked() //create shp test
{
    const char *pszDriverName = "ESRI Shapefile";
    GDALAllRegister();
    OGRRegisterAll();
    GDALDriver *poDriver = OGRSFDriverRegistrar::GetRegistrar()->GetDriverByName(pszDriverName);
    GDALDataset *poDs = poDriver->Create("32.shp", 0, 0, 0, GDT_Unknown, NULL);
    OGRLayer *poLayer = poDs->CreateLayer("roadmarking", NULL, wkbPoint, NULL);
    if (poLayer == NULL)
    {
        //cout << "Layer creation failed!" << endl;
    }
    else
    {
    }
    //cout << "Creating Layer done" << endl;

    // Create a property field
    OGRFieldDefn poFieldID("ID", OFTInteger);
    poFieldID.SetWidth(40);
    OGRFieldDefn poFieldType("Type", OFTInteger);
    poFieldType.SetWidth(40);
    if (poLayer->CreateField(&poFieldID) != OGRERR_NONE) {
        //cout << "ID field creation failed" << endl;
    }
    if (poLayer->CreateField(&poFieldType) != OGRERR_NONE) {
        //cout << "Type field creation failed" << endl;
    }

    // Picture
    int line_N = 90;
    OGRMultiPoint point;
    for (int i = 0; i < line_N; i++) {
        OGRFeature *poFeature = OGRFeature::CreateFeature(poLayer->GetLayerDefn());
        poFeature->SetField("ID", i);
        poFeature->SetField("Type", i);

        OGRPoint p(i,i);
        point.addGeometry(&p);
        poFeature->SetGeometry(&p);

        if (poLayer->CreateFeature(poFeature) != OGRERR_NONE) {
            //cout << "Failed to create feature in shapefile" << endl;
        }
        OGRFeature::DestroyFeature(poFeature);
    }
    GDALClose(poDs);


}





void MainWindow::on_actionNew_point_layer_triggered()
{
    LIPNewLineLayerForm *layerForm = new LIPNewLineLayerForm(nullptr, LIPGeometryType::LIPPoint);
    layerForm->exec();

    QString name=layerForm->returnLayer()->returnGISName();
    QObject* layer = new QObject();
    layer->setObjectName(name);
    layerModel->addItem(layer, QModelIndex());
    projectLayers.append(layerForm->returnLayer());
}


void MainWindow::on_actionNew_line_layer_triggered() //при нажатии на кнопку создания линейного слоя
{
    LIPNewLineLayerForm *layerForm = new LIPNewLineLayerForm(nullptr, LIPGeometryType::LIPLineString);
    layerForm->exec();

    QString name=layerForm->returnLayer()->returnGISName();
    QObject* layer = new QObject();
    layer->setObjectName(name);
    layerModel->addItem(layer, QModelIndex());
    projectLayers.append(layerForm->returnLayer());

}


void MainWindow::on_actionNew_polygon_layer_triggered()
{
    LIPNewLineLayerForm *layerForm = new LIPNewLineLayerForm(nullptr, LIPGeometryType::LIPPolygon);
    layerForm->exec();

    QString name=layerForm->returnLayer()->returnGISName();
    QObject* layer = new QObject();
    layer->setObjectName(name);
    layerModel->addItem(layer, QModelIndex());
    projectLayers.append(layerForm->returnLayer());
}


void MainWindow::on_actionLoad_vector_layer_triggered()
{
    QString fileName=QFileDialog::getOpenFileName(this,"","");
    QByteArray bytea=fileName.toLocal8Bit();
    const char *charname=bytea.data();

}

