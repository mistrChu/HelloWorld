#include"singal.h"
#include"pathdata.h"
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
void *cartcp(void *arg)
{
	int newfd;
   char str[64];
   printf("waiting for client ....\n");
   newfd=recvfrom(servfd,str,64,0,NULL,NULL);
   if(newfd>0)
   str[newfd]=0;
	//int *p=(int *)arg;
	int fd=newfd;
	while(1)
	{
			char buff[1024];
			int cnt;
			int x;
			while(1)
			{
				cnt=read(fd,buff,1024);
				if(cnt==0)
				{
						close(fd);
						printf("client %d exit\n",fd);
						pthread_exit(0);
				}
				write(fd,buff,cnt);
				printf("%s\n",buff);
				
				
			 if(strcmp(buff,"forw")==0)
				x=0;
			 else if(strcmp(buff,"back")==0)
				x=1;
			 else if(strcmp(buff,"rigt")==0)
				x=2;
			 else if(strcmp(buff,"left")==0)
				x=3;
			else if(strcmp(buff,"uppp")==0)
				x=4;
			else if(strcmp(buff,"down")==0)
				x=5;
			else if(strcmp(buff,"stop")==0)
				x=6;
			switch(x)
			{
					case 0:
					{
						dir='w';
						flag1=dir;
						break;
					}
					case 1:
					{
						dir='s';
						flag1=dir;
						break;
					}
					case 2:
					{
						dir='d';
						flag1=dir;
						break;
					}
					case 3:
					{
						dir='a';
						flag1=dir;
						break;
					}
					case 4:
					{
						flag='+';
						if(sp==1000)
						sp=500;
						else
						sp+=100;
						dir=flag1;
						break;
					}
					case 5:
					{
						flag='-';
						if(sp==0)
						sp=500;
						else
						sp-=100;
						dir=flag1;
						break;
					}
					case 6:
					{
						dir='q';
						flag1=dir;
						break;
					}
					default :break; 
						
			}
			
			memset(buff,cnt,0);
			break;
			
		}
		
	 }
						close(fd);
						printf("client %d exit\n",fd);
						pthread_exit(0);
}



