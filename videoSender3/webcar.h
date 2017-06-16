#ifndef WEBCAR_H
#define WEBCAR_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "pathdata.h"
#include <opencv2/opencv.hpp>
using namespace cv;
void webcar();
//void send_webcar();
void *cartcp(void *arg);
//void *carsend(void *arg);
#endif
