QT       += core gui sql
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
    lipframe.cpp \
    liplayercreator.cpp \
    liplayertreeitem.cpp \
    liplayertreemodel.cpp \
    lipmapcalculations.cpp \
    lipmapholder.cpp \
    lipmapscene.cpp \
    lipmessage.cpp \
    lipmultipoint.cpp \
    lipnewattrfeatureform.cpp \
    lipnewlinelayerform.cpp \
    lipnewpointlayerform.cpp \
    lippointlayer_1.cpp \
    lippointrenderer.cpp \
    lippostgisconnectionform.cpp \
    lippostgisprovider.cpp \
    lipproject.cpp \
    liptreewidget.cpp \
    liptypes.cpp \
    lipvectorreader.cpp \
    lipvectorstyleform.cpp \
    main.cpp \
    mainwindow.cpp \


HEADERS += \
    lipaddingitems.h \
    lipfeaturerenderer.h \
    lipframe.h \
    liplayercreator.h \
    liplayertreeitem.h \
    liplayertreemodel.h \
    lipmapcalculations.h \
    lipmapholder.h \
    lipmapscene.h \
    lipmessage.h \
    lipmultipoint.h \
    lipnewattrfeatureform.h \
    lipnewlinelayerform.h \
    lipnewpointlayerform.h \
    lippointlayer_1.h \
    lippointrenderer.h \
    lippostgisconnectionform.h \
    lippostgisprovider.h \
    lipproject.h \
    liptreewidget.h \
    liptypes.h \
    lipvectorreader.h \
    lipvectorstyleform.h \
    mainwindow.h \


FORMS += \
    lipnewattrfeatureform.ui \
    lipnewlinelayerform.ui \
    lipnewpointlayerform.ui \
    lippostgisconnectionform.ui \
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
