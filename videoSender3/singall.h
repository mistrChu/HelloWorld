#ifndef __SINGALL_H__
#define __SINGALL_H__

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdlib.h>
#include <pthread.h>
#include "termios_control.h"
#include <iostream>
#include <signal.h>
#include <termios.h> //操作终端
#include <unistd.h>
#include <assert.h>
#include "kongzhi.h"
void handler(int signo);

void *command(void *arg);
void *carrunning(void *arg);


#endif
