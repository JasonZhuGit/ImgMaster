#-------------------------------------------------
#
# Project created by QtCreator 2018-03-16T15:53:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImgMaster
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view/imageview.cpp \
    view/infopanelsholder.cpp \
    view/procpanelsholder.cpp \
    view/baseprocpanel.cpp \
    controller/corecontroller.cpp \
    model/coreimage.cpp \
    view/viewpanelsholder.cpp \
    view/multiviewpanel.cpp \
    view/imagelistpanel.cpp

HEADERS  += mainwindow.h \
    view/imageview.h \
    view/infopanelsholder.h \
    view/procpanelsholder.h \
    view/baseprocpanel.h \
    controller/corecontroller.h \
    model/coreimage.h \
    view/viewpanelsholder.h \
    view/multiviewpanel.h \
    view/imagelistpanel.h

unix{
    INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

    LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so \
        /usr/local/lib/libopencv_imgproc.so
}

FORMS += \
    view/baseprocpanel.ui \

RESOURCES += \
    res.qrc
