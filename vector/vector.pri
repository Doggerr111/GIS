QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        $$PWD/lipattribute.cpp \
        $$PWD/lipgraphicsitem.cpp \
        $$PWD/liplinegraphicsitem.cpp \
        $$PWD/liplinelayer.cpp \
        $$PWD/lippointgraphicsitem.cpp \
        $$PWD/lippolygongraphicsitem.cpp \
        $$PWD/lippolygonlayer.cpp \
        $$PWD/liptemporarygraphicsitem.cpp \
        $$PWD/lipvectorlayer.cpp \
        $$PWD/lipvectorstyle.cpp \
        vector/lippointlayer.cpp \
        vector/lippoint.cpp

HEADERS += \
        $$PWD/lipattribute.h \
        $$PWD/lipgraphicsitem.h \
        $$PWD/liplinegraphicsitem.h \
        $$PWD/liplinelayer.h \
        $$PWD/lippointgraphicsitem.h \
        $$PWD/lippolygongraphicsitem.h \
        $$PWD/lippolygonlayer.h \
        $$PWD/liptemporarygraphicsitem.h \
        $$PWD/lipvectorlayer.h \
        $$PWD/lipvectorstyle.h \
        vector/lippointlayer.h \
        vector/lippoint.h



INCLUDEPATH += /usr/include/gdal
LIBS += /usr/lib/libgdal.so

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
