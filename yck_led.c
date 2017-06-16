#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<wiringPi.h>

int servfd;
int tcp_serv_init(int serv_port)
{
  
  int port=serv_port;
  
  servfd = socket(AF_INET,SOCK_STREAM,0);
  struct sockaddr_in  servaddr;
  servaddr.sin_family=AF_INET;
  servaddr.sin_addr.s_addr =  htonl(INADDR_ANY);
  servaddr.sin_port= htons(port);
  
  int ret;
  ret = bind(servfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
  if(ret<0)
  {
	  printf("bind error\n");

      exit(1);
  }
  listen(servfd,5);	
  return servfd;
}

void led_init()
{
    pinMode(8,OUTPUT);
	pinMode(9,OUTPUT);
	pinMode(7,OUTPUT);
	pinMode(0,OUTPUT);


	digitalWrite(8,HIGH);
	digitalWrite(9,HIGH);
	digitalWrite(7,HIGH);
	digitalWrite(0,HIGH);	
}
int main()
{
  tcp_serv_init(1234);
   wiringPiSetup();
   led_init();
  
  
  int newfd;
  printf("waiting for client ....\n");
  newfd = accept(servfd,NULL,NULL);
  printf("client connect succeful\n");
  
  char str[1024];
   while(1)
   {
	  read(newfd,str,1024);
	  printf("%s\n",str);
	 if(strcmp(str,"on")==0)
	 {
	   digitalWrite(8,LOW);
	   digitalWrite(9,LOW); 
	   // printf("%s",str);
	 }
	 else if(strcmp(str,"off")==0)
	 {
		 digitalWrite(8,HIGH);
	     digitalWrite(9,HIGH); 
	     //printf("%s",str);
	 }
	
	 
	 
	 
   }  
   close(newfd);
   close(servfd);
   return 0;
 }
