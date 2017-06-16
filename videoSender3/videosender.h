#ifndef VIDEOSNEDER_H
#define VIDEOSNEDER_H

#include <opencv.hpp>
using namespace cv;
#include <QTimer>
#include <QtNetwork/QUdpSocket>
//#include <raspicam/raspicam_cv.h>
//using namespace raspicam;

class VideoSender
{
public:
    VideoSender();
    ~VideoSender();
    void start();
    void stop();
    void sendPicture();
private:

    VideoCapture camera;
    QUdpSocket *sender;
    QHostAddress dstip;
    QHostAddress srcip;
    quint16  dstport;
    quint16  srcport;
    //RaspiCam_Cv rpicam;
};
void  *websend(void *arg);
#endif // MAINWINDOW_H
