#include "singall.h"
#include "pathdata.h"

using namespace std;
void handler(int signo)
	{
		stop();
		exit(0);
	}
	
	

void *command(void *arg)
{
	while(1)
	{
		flag=my_getch();
		if((flag=='w')||(flag=='s')||(flag=='a')||(flag=='d')||(flag=='q'))
		{
			dir=flag;
			flag1=dir;
		}
		else 
		{
			if(flag=='+')
			{
				if(sp==1000)
				sp=500;
				else
				sp+=100;
			}
			if(flag=='-')
			{
				if(sp==0)
				sp=500;
				else
				sp-=100;
			}
			
			dir=flag1;
		}
	} 	   
}

void *carrunning(void *arg)
{
	while(1)
	{
		
		switch(dir)
	   {
	    case 'q':
				stop();
				break;
	    case 'w':
				forward();
				break;
	    case 's':
				back();
				break;
	    case 'd':
				turn_right();
				break;
	    case 'a':
				turn_left();
				break;
				
		default :break;    
	   }
	   delay(1);
   }
}
