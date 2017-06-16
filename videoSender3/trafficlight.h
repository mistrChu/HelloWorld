#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__
#include <opencv2/opencv.hpp>
#include "pathdata.h"
#include <sys/time.h>
#include <stdio.h>
#include <wiringPi.h>
using namespace cv;
using namespace std;
int detectTrafficLight(Mat &image);
void *trafficlight(void *arg);

#endif
