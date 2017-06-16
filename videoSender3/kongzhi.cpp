#include <iostream>
#include"kongzhi.h"

using namespace std;

void speed(int spp)
	{
		int i;
		for(i=0;i<100;i++)
		{
			digitalWrite(2,HIGH);
			digitalWrite(3,HIGH);
			delayMicroseconds(sp);
			digitalWrite(2,LOW);
			digitalWrite(3,LOW);
			delayMicroseconds(1000-spp);
		}
	}
		
void forward()
	{
		digitalWrite(8,HIGH);
		digitalWrite(9,LOW);
		digitalWrite(7,HIGH);
		digitalWrite(0,LOW);
		speed(sp);
	}
void back()
	{
		digitalWrite(8,LOW);
		digitalWrite(9,HIGH);
		digitalWrite(7,LOW);
		digitalWrite(0,HIGH);
		speed(sp);
	}
void turn_right()
	{
		digitalWrite(8,HIGH);
		digitalWrite(9,LOW);
		digitalWrite(7,LOW);
		digitalWrite(0,LOW);
		speed(sp);
	}
		
void turn_left()
	{
		digitalWrite(8,LOW);
		digitalWrite(9,LOW);
		digitalWrite(7,HIGH);
		digitalWrite(0,LOW);
		speed(sp);
	}
		
void stop()
	{
		digitalWrite(8,LOW);            //STOP
		digitalWrite(9,LOW);
		digitalWrite(7,LOW);		
		digitalWrite(0,LOW);
	}
