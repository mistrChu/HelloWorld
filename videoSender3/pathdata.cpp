#include"pathdata.h"
#include <opencv2/opencv.hpp>
using namespace cv;

int servfd=0;
int sp=500;
char dir;
char flag;
char flag1;
int red1=0;
Mat cvImage;
pthread_mutex_t mutex;
pthread_cond_t cond;
