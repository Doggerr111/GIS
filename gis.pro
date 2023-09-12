QT       += core gui
include(vector/vector.pri)
include(treeView/treeView.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lipaddingitems.cpp \
    lipfeaturerenderer.cpp \
    liplayercreator.cpp \
    liplayertreeitem.cpp \
    liplayertreemodel.cpp \
    lipmapcalculations.cpp \
    lipmapholder.cpp \
    lipmapscene.cpp \
    lipmultipoint.cpp \
    lipnewlinelayerform.cpp \
    lipnewpointlayerform.cpp \
    lippoint.cpp \
    lippointgraphicsitem.cpp \
    lippointlayer_1.cpp \
    lippointrenderer.cpp \
    liptypes.cpp \
    lipvectorlayer.cpp \
    lipvectorreader.cpp \
    lipvectorstyle.cpp \
    lipvectorstyleform.cpp \
    main.cpp \
    mainwindow.cpp \


HEADERS += \
    lipaddingitems.h \
    lipfeaturerenderer.h \
    liplayercreator.h \
    liplayertreeitem.h \
    liplayertreemodel.h \
    lipmapcalculations.h \
    lipmapholder.h \
    lipmapscene.h \
    lipmultipoint.h \
    lipnewlinelayerform.h \
    lipnewpointlayerform.h \
    lippoint.h \
    lippointgraphicsitem.h \
    lippointlayer_1.h \
    lippointrenderer.h \
    liptypes.h \
    lipvectorlayer.h \
    lipvectorreader.h \
    lipvectorstyle.h \
    lipvectorstyleform.h \
    mainwindow.h \


FORMS += \
    lipnewlinelayerform.ui \
    lipnewpointlayerform.ui \
    lipvectorstyleform.ui \
    mainwindow.ui

INCLUDEPATH += /usr/include/gdal
LIBS += /usr/lib/libgdal.so

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc

DISTFILES += \
    treeView/treeView.pri \
    vector/test.pri
