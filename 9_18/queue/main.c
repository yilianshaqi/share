#include<stdio.h>
#include"queue.h"
int main()
{
	Data *queue;
	queue=creatqueue();
	if(NULL==queue)
	{
		return ;
	}
	data_t tdata;
	int i;
	for(i=5;i<25;i++)
	{
		inqueue(queue,i);
	}
	for(i=1;i<10;i++)
	{
		outqueue(queue,&tdata);
		printf("%5d",tdata);
	}
	printf("\n");
	destory(queue);
	return ;
}

