#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>


int main()
{
    wiringPiSetup();
	pinMode(22,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(0,OUTPUT); 
	/*digitalWrite(9,HIGH);
	digitalWrite(7,HIGH);
	digitalWrite(0,HIGH);
	digitalWrite(22,LOW);
	digitalWrite(9,LOW);*/
	int i=0,j=0;
	int color[]={9,7,0};
	    softPwmCreate(9,0,254);
	    softPwmCreate(7,0,254);
	    softPwmCreate(0,0,254);
	    
while(1)
 {
   for(j=0;j<3;j++)
	 { 
	     while(1)
		   { 
		     softPwmWrite(color[j],i);
		     i+=2;
		     if(i==254)
			  break;
		     delay(15);
		   }
      
        while(1)
		  { 
		    softPwmWrite(color[j],i);
		    i-=2;
		    if(i==0)
			  break;
		    delay(15);
		  }
       softPwmWrite(color[j],255);
 
     }
   
     j=0;
      
  } 
      
	return 0;
 }




	  
