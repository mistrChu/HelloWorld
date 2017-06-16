#ifndef __SINGAL_H__
#define __SINGAL_H__

#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>
#include "termios_control.h"
#include <iostream>
#include "kongzhi.h"
#include "webcar.h"
void handler(int signo);

void *command(void *arg);
void *carrunning(void *arg);
void *cartcp(void *arg);

#endif
