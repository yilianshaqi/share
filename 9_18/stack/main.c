#include<stdio.h>
#include"stack.h"
int  main()
{
	Data *stack;
	stack=creatstack();
	if(stack==NULL)
	{
		return ;
	}
	int i;
	data_t tdata;
	for(i=5;i<20;i++)
	{
		instack(stack,i);
	}
	for(i=10;i<20;i++)
	{
		outstack(stack,&tdata);
		printf("%5d",tdata);
	}
	printf("\n");
	destory(stack);
	return ;
}

