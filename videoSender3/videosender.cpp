#include "videosender.h"
#include <stdlib.h>
#include <opencv.hpp>
#include "pathdata.h"
using namespace cv;

#include <QFile>
#include <QImage>
#include <stdio.h>


void  *websend(void *arg)
{
   // QApplication a(argc, argv);
    VideoSender sender;
  //  sender.start();
    while(1)
    {
        sender.sendPicture();
        waitKey(33);
    }
  //  sender.stop();
	waitKey();
   // return a.exec();
}

VideoSender::VideoSender()
{
    sender = new QUdpSocket();
    //ip = QHostAddress(ui->lineEdit->text());
    //port = ui->lineEdit_2->text().toInt();
    dstip = QHostAddress("192.168.6.247");
    dstport = 5555;
    srcip = QHostAddress::Any;
    srcport = 6666;
    sender->bind(srcip, srcport);
    
    //rpicam.set(CV_CAP_PROP_FORMAT, CV_8UC1);
    //rpicam.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    //rpicam.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
}

VideoSender::~VideoSender()
{
    delete sender;

}

void VideoSender::start()
{
	if(!camera.open(0))
    camera.open(0);
    //if(!rpicam.open())
	//	exit(-1);
}
void VideoSender::stop()
{
    camera.release();
    //rpicam.release();
}
void VideoSender::sendPicture()
{
  //  Mat cvImage;    //定义矩阵，用来存放图像
  //  camera.read(cvImage); // 从摄像头采集图像
   // rpicam.grab();
   // rpicam.retrieve(cvImage);
    if(cvImage.empty())
		return ;
	//imwrite("test.jpg", cvImage);
	//printf("get photo");
	
    QImage qtImage; // 把opencv的图像转换为qt的图像
        qtImage = QImage(cvImage.data,
                 cvImage.size().width,
                 cvImage.size().height,
                 QImage::Format_RGB888);

// #include <QFile>
    // 保存图像
    qtImage.save("test.jpg", "JPEG");
    
    //打开图像
    QFile file("test.jpg");
    file.open(QIODevice::ReadOnly);
    // 把图像读到 buffer
    QByteArray buffer;
    buffer = file.readAll();
       //发送图像
    sender->writeDatagram(
                buffer, buffer.size(),
                dstip, dstport
                );
    file.close();
}



