#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <wiringPi.h>
int j;
int csb()
{
	 int clientfd;
 
  clientfd= socket(AF_INET,SOCK_STREAM,0);
 
  struct sockaddr_in  myservaddr;
  myservaddr.sin_family=AF_INET;
  myservaddr.sin_addr.s_addr =  inet_addr("127.0.0.1");
  myservaddr.sin_port= htons(1234);
  connect(clientfd,&myservaddr,sizeof(myservaddr));

   char str[1024]; 
  
	   
	   int val ;
	  long  t1,t2;
	   float dis;
	   struct timeval start,end;
   
	 
   
    
		 
	  while(1)
		   {
			  val =digitalRead(9);
			  if(val==1)
		     {
			   printf("HIGH\n");
			   break;
		     }
		     else
		     continue;
			
		  }
		  
	  gettimeofday(&start,NULL);
	  
	  while(1)
		  {
			  val =digitalRead(9);
			  if(val==0)
		       {
			   printf("LOW\n");
			   break;
		       }
		      else
		      continue;
		   } 
		   
		   gettimeofday(&end,NULL);
		   
		long t1 = start.tv_sec * 1000000 + start.tv_usec;
		long t2 = end.tv_sec * 1000000 + end.tv_usec;
	    float dis = (float)(t2-t1) /1000000*34000/2;
		printf("%fcm\n",dis);
		  
	   delay(1000);
   if(dis>=20)
    j=1;
    else 
    j=0;
    if(j==1)
	  
		  str[]={"1"};
		  else str[]={"0"};
	  write(clientfd,str,strlen(str)+1); 
	    
   }  
   close(clientfd);
   // return j;
    //break;
}


int main()
{
	   wiringPiSetup();
       pinMode(8,OUTPUT);
	   pinMode(9,INPUT);
	   digitalWrite(8,LOW);
		 digitalWrite(8,HIGH);
		 delayMicroseconds(15);
		 digitalWrite(8,LOW); 
		
  
   
   while(1)
   { csb();
	  
	 
   return 0;
 }
