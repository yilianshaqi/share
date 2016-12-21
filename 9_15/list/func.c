#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"
Data *create(void)
{
	Data *plist=NULL;
	plist=(Data *)malloc(sizeof(Data));
	if(NULL==plist)
	{
		return ;
	}
	memset(plist,0,sizeof(Data));
	return plist;
}




int insert(Data * plist, int offset, data_t data)
{
	if(plist==NULL || offset>plist->inum || plist->inum>=LEN || offset<0)
	{
		return LIST_ERROR;
	}
	int i;
	for(i=plist->inum-1;i>=offset;i--)
	{
		plist->data[i+1]=plist->data[i];
	}
	plist->data[offset]=data;
	plist->inum++;
	return LIST_OK;
}



int delete(Data * plist, int offset ,data_t *data)
{
	if(plist==NULL || offset>=plist->inum || offset <0)
	{
		return LIST_ERROR;
	}
	int i;
	*data=plist->data[offset];
	for(i=offset;i<plist->inum-1;i++)
	{
		plist->data[i+1]=plist->data[i];
	}
	plist->inum--;
	return LIST_OK;
}


int updata(Data * plist ,int offset ,data_t data )
{
	if(plist==NULL ||offset>=plist->inum || offset<0)
	{
		return LIST_ERROR;
	}
	plist->data[offset]=data;
	return LIST_OK;
}



int find(Data *plist, data_t data)
{	
	if(plist==NULL)
	{
		return LIST_ERROR;
	}
	int i;
	for(i=0;i<plist->inum;i++)
	{
		if(plist->data[i]==data)
		{
			printf("position=%d\n",i);
			return LIST_OK;
		}
	}
	return NO_DATA;
}


int show(Data *plist)
{
	if(plist==NULL )
	{
		return LIST_ERROR;
	}
	int i;
	for(i=0;i<plist->inum;i++)
	{
		printf("%5d",plist->data[i]);
	}
	printf("\n");
	return LIST_OK;
}

