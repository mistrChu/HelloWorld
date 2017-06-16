#ifndef __KONGZHI_H__
#define __KONGZHI_H__

#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include"pathdata.h"
void speed(int spp);	
void forward();	
void back();	
void turn_right();		
void turn_left();		
void stop();
#endif
