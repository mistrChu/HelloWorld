#include<stdio.h>
#include<wiringPi.h>
int i;
int main()
{
    wiringPiSetup();
	pinMode(22,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(0,OUTPUT); 
	digitalWrite(9,HIGH);
	digitalWrite(7,HIGH);
	digitalWrite(0,HIGH);
	digitalWrite(22,HIGH);
	digitalWrite(9,LOW);
	int total =100;
	int step =2;
	int time =total;
	int i;
	//softPwmCreate(9,0,100);
	//softPwmCreate(7,0,100);
	//softPwmCreate(0,0,100);
	while(1)
	{
		for(i=0;i<1;i++)
	 {
		time-=step;
		digitalWrite(22,HIGH);
		delay(time);
		digitalWrite(22,LOW);
		delay(total-time);
		
		if(time<=0)
		time=total;
		
	}	
	
	for(i=1;i>=0;i--)
	 {
		time-=step;
		digitalWrite(22,LOW);
		delay(time);
		digitalWrite(22,HIGH);
		delay(total-time);
		
		if(time<=0)
		time=total;
		
	}	
	  /*softPwmWrite(9,255);
	  softPwmWrite(7,100);
	  softPwmWrite(0,0);
	   
	  delay(1000);
	   
	   softPwmWrite(9,0);
	   softPwmWrite(7,100);
	   softPwmWrite(0,255);
	   
	   delay(1000);*/
	}
	return 0;
}
