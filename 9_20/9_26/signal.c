/*************************************************************************
    > File Name: signal.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Sun 25 Sep 2016 11:14:05 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

	int num=1;
void *func1(void*arg)
{
	int i=1;
	while(i--)
	{
		printf("num=%d\r\n",num);
		num+=10;
		printf("hello\r\n");
//		printf("num=%d\r\n",num);
	}
//	pthread_exit(0);
}

void* func2(void*arg)
{
	int i=1;
	while(i--)
	{
		printf("num=%d\r\n",num);
		num+=100;
		printf("world\r\n");
//		printf("num=%d\r\n",num);
	}
//	pthread_exit(0);
}
int main()
{
	pthread_t tid1=0;
	pthread_t tid2=2;
//	pthread_create(&tid1,NULL,func1,NULL);
	if(0>pthread_create(&tid1,NULL,func1,NULL))
	{
		printf("create pthread error\n");
		return -1;
	}
	
	if(pthread_create(&tid2,NULL,func2,NULL)<0)
	{
		printf("create pthread error\n");
		return -1;
	}   
	sleep(3);
	return 0;
}
