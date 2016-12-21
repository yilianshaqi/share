#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
Data *creatstack(void)
{
	Data * pstack;
	pstack=(Data*)malloc(sizeof(Data));
	if(pstack==NULL)
	{
		return pstack;
	}
	memset(pstack,0,sizeof(Data));
	pstack->itop=-1;
	return pstack;
}


int instack(Data * pstack, data_t tdata)
{
	if(NULL==pstack || pstack->itop==DATA_LEN-1)
	{
		return STACK_ERROR;
	}
	pstack->itop++;
	pstack->data[pstack->itop]=tdata;
	return STACK_OK;
}

int outstack(Data *pstack, data_t *tdata)
{
	if(NULL==pstack || tdata==NULL || pstack->itop==-1)
	{
		return STACK_ERROR;
	}
	*tdata=pstack->data[pstack->itop];
	pstack->itop--;
	return STACK_OK;
}

int destory(Data *pstack)
{
	if(NULL==pstack)
	{
		return STACK_ERROR;
	}
	free(pstack);
	pstack=NULL;
	return STACK_OK;
}

int show(Data * pstack)
{
	if(NULL==pstack)
	{
		return STACK_ERROR;
	}
	int i;
	for(i=0;i<=pstack->itop;i++)
	{
		printf("%5d",pstack->data[i]);
	}
	printf("\n");
	return STACK_OK;
}

