#include "videosender.h"
#include <QApplication>
#include <opencv.hpp>
#include "kongzhi.h"
#include "singall.h"
#include "termios_control.h"
#include "webcar.h"
#include "csb_car.h"
#include "pathdata.h"
#include "trafficlight.h"
using namespace std;




int main()
{
	signal(SIGINT,handler);
	wiringPiSetup();
	pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(0,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(12,OUTPUT);
	pinMode(13,INPUT);

	digitalWrite(8,LOW);
	digitalWrite(9,LOW);
	digitalWrite(7,LOW);
	digitalWrite(0,LOW);
	digitalWrite(2,LOW);
	digitalWrite(3,LOW);
	
	
    pthread_t tid1,tid2,tid3,tid4,tid5,tid6;
	//pthread_mutex_init(&mutex,NULL);
	//pthread_cond_init(&cond,NULL);
	pthread_create(&tid1,NULL,command,NULL);
	pthread_create(&tid2,NULL,carrunning,NULL);
	pthread_create(&tid3,NULL,cartcp,NULL);
	pthread_create(&tid4,NULL,csb_car,NULL);		
	pthread_create(&tid5,NULL,trafficlight,NULL);
    pthread_create(&tid6,NULL,websend,NULL);


	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid4,NULL);	
    pthread_join(tid5,NULL);
    pthread_join(tid6,NULL);
	//pthread_mutex_destroy(&mutex);
	//pthread_cond_destroy(&cond);
	 
return 0;
}

