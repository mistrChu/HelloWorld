#include<stdio.h>
#include<wiringPi.h>

int i,j;
int seg[]={22,2,3,12,13,14,30,21};
int color[]={9,7,0};
int main()
{
	wiringPiSetup();
	pinMode(22,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(0,OUTPUT);
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(12,OUTPUT);
	pinMode(13,OUTPUT);
	pinMode(14,OUTPUT);
	pinMode(30,OUTPUT);
	pinMode(21,OUTPUT);

while(1)
  {	
	
	for(j=0;j<3;j++)
   {
	digitalWrite(9,HIGH);
	digitalWrite(7,HIGH);
	digitalWrite(0,HIGH);
	digitalWrite(2,HIGH);
	digitalWrite(3,HIGH);
	digitalWrite(12,HIGH);
	digitalWrite(13,HIGH);
	digitalWrite(14,HIGH);
	digitalWrite(30,HIGH);
	digitalWrite(21,HIGH);
	digitalWrite(22,HIGH);
	
	
	
	digitalWrite(color[j],LOW);
	    for(i=0;i<8;i++)
		{
			
		 digitalWrite(seg[i],LOW);
		 delay(200);
		 
		//digitalWrite(seg[i],HIGH);
		// delay(1000);
		 }
		 for(i=7;i>=0;i--)
		{
			
		 digitalWrite(seg[i],HIGH);
		 delay(200);
		 
		//digitalWrite(seg[i],HIGH);
		// delay(1000);
		 }
		 
	 
	  //   i=0; 
	
	     digitalWrite(color[j],HIGH);
	   
	
      }
    
    j=0;
	
  }
	return 0;
}
