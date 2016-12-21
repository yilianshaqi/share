
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include"pthread.h"
int main()
{
	pthread_t tid1=0;
	pthread_t tid2=0;
	int math[]={9,4,8,2,4,5,1,5};
	int str[]={12,34,89,23,89,100,99,66};
	int *point=NULL;
	int ret=pthread_mutex_init(&mutex,NULL);
	printf("%d\n",ret);
	if(ret<0)
	{
			perror("init mutex");
			return -1;
	}       
	if(pthread_create(&tid1,NULL,rank,(void *)math)<0)
	{
		perror("create pthread");
		return -1;
	}
	if(pthread_create(&tid2,NULL,rank,(void *)str)<0)
	{
		perror("create pthread");
		return -1;
	}
	pthread_join(tid1,(void *)&point);
	int i;
	for(i=0;i<MATH_SIZE;i++)
	{
		printf("%d\t",point[i]);
	}
	pthread_join(tid2,(void *)&point);
	for(i=0;i<MATH_SIZE;i++)
	{
		printf("%d\t",point[i]);
	}

}
