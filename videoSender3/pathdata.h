#ifndef __PATHDATA_H__
#define __PATHDATA_H__
#include <pthread.h>
#include <opencv2/opencv.hpp>
using namespace cv;
extern int servfd;
extern int sp;
extern  char dir;
extern char flag;
extern  char flag1;
extern int red1;
extern Mat cvImage;
extern pthread_mutex_t mutex;
extern pthread_cond_t cond;

#endif
