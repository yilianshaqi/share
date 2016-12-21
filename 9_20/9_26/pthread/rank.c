#include<stdio.h>
#include<pthread.h>
#include"pthread.h"

void *rank(void * arg)
{
	int i,j;
	int temp;
	int *agv=(int *)arg;
	for(i=0;i<MATH_SIZE-1;i++)
	{
		for(j=0;j<MATH_SIZE-1-i;j++)
		{
			if((int *)agv[j]<(int *)agv[j+1])
			{
				temp=agv[j];
				agv[j]=agv[j+1];
				agv[j+1]=temp;
			}
		}
	}
	pthread_exit((void *)agv);
}

