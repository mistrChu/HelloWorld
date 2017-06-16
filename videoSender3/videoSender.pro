#-------------------------------------------------
#
# Project created by QtCreator 2016-07-06T15:46:57
#
#-------------------------------------------------

QT       += core gui
QT      += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = videoSender
TEMPLATE = app


SOURCES += main.cpp \
    videosender.cpp \
    csb_car.cpp \
    kongzhi.cpp \
    pathdata.cpp \
    singall.cpp \
    trafficlight.cpp \
    webcar.cpp \
    termios_control.cpp

HEADERS  += \
    videosender.h \
    csb_car.h \
    kongzhi.h \
    pathdata.h \
    singall.h \
    termios_control.h \
    trafficlight.h \
    webcar.h

FORMS    +=


INCLUDEPATH+=/usr/include	\
                   /usr/include/opencv2 \
                    /usr/include/opencv	\
                    /usr/local/include 
                    

LIBS+=-lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_core -lopencv_imgproc -lopencv_highgui -lwiringPi -lpthread  


DISTFILES += \
    videoSender.pro.user
