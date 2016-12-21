/*************************************************************************
    > File Name: ptread.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Mon 26 Sep 2016 03:51:45 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
#define BUF_SIZE 20
int s=9;
sem_t sem;
sem_t sem1;
pthread_exit(&s);
}
int main()
{

	//create pthread
	sem_init(&sem,0,1);
	sem_init(&sem1,0,0);
	pthread_t tid1=0;
	pthread_t tid2=0;
	char string[]={'h','y','w','o','r','l','d'};
	char math[]={'9','5','8','6','3','2','0'};
	if(pthread_create(&tid1,NULL,func,(void *)string))
	{
		printf("create error\n");
		return -1;
	}
	if(0!=pthread_create(&tid2,NULL,func,(void *)math))
	{
		printf("create error\n");
		return -1;
	}
	//set sem
	int *p;
	pthread_join(tid1,(void *)&p);
	pthread_join(tid2,NULL);
	printf("%d",*p);
	return 0;
}
