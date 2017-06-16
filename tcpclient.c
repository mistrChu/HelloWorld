#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
  int clientfd;
  
  clientfd= socket(AF_INET,SOCK_STREAM,0);
 
  struct sockaddr_in  myservaddr;
  myservaddr.sin_family=AF_INET;
  myservaddr.sin_addr.s_addr =  inet_addr("127.0.0.1");
  myservaddr.sin_port= htons(1234);
  connect(clientfd,&myservaddr,sizeof(myservaddr));

   char str[1024];
   
   while(1)
   {
	  scanf("%s",str);
	  write(clientfd,str,strlen(str)+1);   
   }  
   close(clientfd);
   return 0;
 }
