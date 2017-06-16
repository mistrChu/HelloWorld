#include "csb_car.h"
#include "pathdata.h"
using namespace std;
 #define Trig   12
 #define Echo   13
 float dis=0;
 

int  csb()
{
	   int val ;
	   long t1,t2;
	   struct timeval start,end;
   
		 digitalWrite(Trig,LOW);
		 digitalWrite(Trig,HIGH);
		 delayMicroseconds(15);
		 digitalWrite(Trig,LOW); 
	  while(1)
		   {
			  val =digitalRead(Echo);
			  if(val==1)
		     {
		//	   printf("HIGH\n");
			   break;
		     }
		     else
		     continue;
			
		  }
		  
	  gettimeofday(&start,NULL);
	  
	  while(1)
		   {
			  val =digitalRead(Echo);
			  if(val==0)
		       {
			//   printf("LOW\n");
			   break;
		       }
		      else
		      continue;
		   } 
		   
		   gettimeofday(&end,NULL);
		   
		 t1 = start.tv_sec * 1000000 + start.tv_usec;
		 t2 = end.tv_sec * 1000000 + end.tv_usec;
	     dis = (float)(t2-t1) /1000000*34000/2;
	//	printf("%fcm\n",dis);
		  
	 //  delay(1000);
   
    return  dis;
}
void *csb_car(void *arg)
{
	while(1)
	{
		dis=csb();
		
		if(red1==1)
		{
		dir='q';
		flag1=dir;
		//continue;
	    }
		//{pthread_mutex_lock(&mutex);
		//pthread_cond_wait(&cond,&mutex);
	//}
	else if(red1==0)
	{
		
		if(dis<=30)
		{
			delay(10);
			if(dis<=30)
			{
				dir='q';
				flag1=dir;
			}
		}
		if(dis<=60&&dis>30)
		{
			dir='a';
			flag1=dir;
			delay(3000);
		}
		if(dis>60)
		{
			dir='w';
			flag1=dir;
		}
	}
		printf("%c\n",dir);
		delay(1000);
		// pthread_mutex_unlock(&mutex);
   // pthread_yield();	
	}
}
