QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    $$PWD/lipcircle.cpp \
    $$PWD/lipedge.cpp \
    $$PWD/liptriangle.cpp \
    $$PWD/liptriangulation.cpp \
    $$PWD/lipvoronoidiagram.cpp



HEADERS += \
    $$PWD/lipcircle.h \
    $$PWD/lipedge.h \
    $$PWD/liptriangle.h \
    $$PWD/liptriangulation.h \
    $$PWD/lipvoronoidiagram.h





INCLUDEPATH += /usr/include/gdal
LIBS += /usr/lib/libgdal.so

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
