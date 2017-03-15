#include<stdio.h>
int ret;
int main()
{
	  /*FILE *fp;
	  fp = fopen("test.txt","w");
	  fprintf(fp,"helloworld111\n");
	  fprintf(stdout,"helloworld222\n");
	  fclose(fp);
	  
	  char str[100];
	  FILE *fp2;
	  fp2 = fopen("test.txt","r");
	  fscanf(fp2,"%s",str);
	  printf("result:%s\n",str);
	  fclose(fp2);*/
  
	  char ch;
	  
	  FILE *fp1;
	  FILE *fp2;
  
  
	  fp1 = fopen("test.txt","r");
	  fp2 = fopen("test1.txt","w");
	  while(1)
        {
		  ret = fscanf(fp1,"%c",&ch);
		  if(ret<=0) 
			break;
		  
		  cfprintf(fp2,"%c", ch);
		  printf("result:%c\n",ch);
		  
		}
    
      fclose(fp2);
      fclose(fp1);
  
      return 0;
 
 }
