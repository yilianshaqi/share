#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"
Data * creatqueue(void)
{
	Data * pque;
	pque=(Data* )malloc(sizeof(Data));
	if(NULL==pque)
	{
		return pque;
	}
	memset(pque,0,sizeof(Data));
	return pque;
}
int inqueue(Data *pque, data_t tdata)
{
	if(NULL==pque )
	{
		return QUEUE_ERROR;
	}
	Data *pnode;
	pnode=creatqueue();
	if(NULL==pnode)
	{
		return QUEUE_ERROR;
	}
	Data* ptemp;
	pnode->data=tdata;
	if(pque->pnext==NULL)
	{
		pque->pnext=pnode;
		pque->data=(data_t)pnode;
	}
	else
	{
		ptemp=(Data *)pque->data;
		ptemp->pnext=pnode;
		pque->data=(data_t)pnode;
	}
	return QUEUE_OK;
}
int outqueue(Data *pque,data_t *tdata)
{
	if(NULL==pque ||tdata==NULL || pque->pnext==NULL)
	{
		return QUEUE_ERROR;
	}
	Data *ptemp;
	ptemp=pque->pnext;
	pque->pnext=ptemp->pnext;
	*tdata=ptemp->data;
	free(ptemp);
	ptemp=NULL;
}
int destory(Data *pque)
{
	if(NULL==pque)
	{
		return QUEUE_ERROR;
	}
	Data * ptemp=pque->pnext;
	Data * pdel;
	while(ptemp!=NULL)
	{
		pdel=ptemp;
		ptemp=ptemp->pnext;
		free(pdel);
		pdel=NULL;
	}
	free(pque);
	pque=NULL;
	return QUEUE_OK;	
}


