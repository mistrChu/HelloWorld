#include "webcar.h"
#include "pathdata.h"
#include <opencv2/opencv.hpp>
#include <fstream>
using namespace cv;
using namespace std;
VideoCapture camera;
void webcar()
{
	
  servfd = socket(AF_INET,SOCK_DGRAM,0);
  printf("servf=%d\n",servfd);
  
  struct sockaddr_in  servaddr;
  servaddr.sin_family=AF_INET;
  servaddr.sin_addr.s_addr =  htonl(INADDR_ANY);
  servaddr.sin_port= htons(8888);
  int ret;
  ret = bind(servfd,(struct sockaddr*)&servaddr,sizeof(struct sockaddr_in));
  if(ret<0)
  {
	  printf("bind error\n");

      exit(1);
  }
  struct sockaddr_in peer;
  socklen_t peerlen;
  
  }
  /*
  void send_webcar()
  { 
	  camera.open(0);
	  int clientfd=socket(AF_INET,SOCK_DGRAM,0);
	printf("%d\n",clientfd);
	struct sockaddr_in saddr;
	saddr.sin_family=AF_INET;
	saddr.sin_port=htons(5555);
	saddr.sin_addr.s_addr=inet_addr("192.168.6.247");
	
	  //camare read
    Mat cvImage;    //定义矩阵，用来存放图像
    camera.read(cvImage); // 从摄像头采集图像
	//cv::namedWindow("Extracted Frame");
	//cv::imshow("Extracted Frame",cvImage);
	cout<<"ok imshow?"<<endl;
    imwrite("test.jpg", cvImage);
 // QImage qtImage; // 把opencv的图像转换为qt的图像
 //   qtImage = QImage(cvImage.data,
 //          cvImage.size().width,
 //        cvImage.size().height,
 //      QImage::Format_RGB888);
    // 显示图像
    // 保存图像
//    qtImage.save("test.jpg", "JPEG");
    //打开图像
      fstream file1;  
		file1.open("test.jpg",ios::binary|ios::in);  
    if(!file1.is_open())
    {
        cerr<<"cant open file to read"<<endl;
    }
    char buff[1024];
	//file1.read(buff,1024);
	//sendto(clientfd,buff,sizeof(buff),0,(struct sockaddr *)&saddr,sizeof(saddr));
	
    while(!file1.eof())
    {
		
        file1.read(buff,1024);
		printf("receive from %s\n" ,inet_ntoa( saddr.sin_addr));
		//printf("%s\n",buff);
		       //发送图像
		
		 if( sendto(sock, buff, strlen(buff), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0){
            perror("sendto");
            close(sock);
            break;
        }else{
			printf("clinet send success!\n");
		}
		
		//printf("%d\n",clientfd);
		//printf("ok\n");
		
		if(sendto(clientfd,buff,sizeof(buff),0,(struct sockaddr *)&saddr,sizeof(saddr))< 0)
		{
			 perror("sendto");
             close(clientfd);
            break;
        }
        else
        {
			printf("clinet send success!\n");
		}
    }
    file1.close();
}

*/
  void *cartcp(void *arg)
{
	webcar();
	int newfd;
		char buff[64];
		int x;
		int cnt=0;
		printf("waiting for client ....\n");
	
	//int *p=(int *)arg;
	//int fd=newfd;
	while(1)
	{
		newfd=recvfrom(servfd,buff,64,0,NULL,NULL);
		printf("%d\n",newfd);
	//fputs(buff,stdout);
	
		cnt=newfd;
		if(newfd>0)
		buff[newfd]=0;
		printf("%s\n",buff);
		//write(1,buff,cnt);
		
		
		/*
			char buff[1024];
			int cnt;
			int x;
			while(1)
			{
				cnt=read(servfd,buff,1024);
				printf("%d\n",cnt);
				if(cnt==0)
				{
						close(servfd);
						printf("client %d exit\n",servfd);
						pthread_exit(0);
				}
				write(servfd,buff,cnt);
				//printf("%s\n",buff);
				//write(1,buff,cnt);
				
				*/
				
				//fputs(buff,stdout);
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
		//	break;
			
		//}
		
	 }
						close(servfd);
						printf("client %d exit\n",servfd);
						pthread_exit(0);
						
}
/*
 void *carsend(void *arg)
 {
	 send_webcar();
	 
	 }
	 */
