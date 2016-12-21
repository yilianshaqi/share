#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"link.h"
Data *creatlink(void)
{
	Data *plink;
	plink=(Data *)malloc(sizeof(Data));
	if(NULL==plink)
	{
		return plink;
	}
	memset(plink,0,sizeof(Data));
	return plink;
}

int insertlink(Data * plink,data_t data)
{
	if(NULL==plink )
	{
		return LINK_ERROR;
	}
	Data *pnode;
	pnode=creatlink();
	if(NULL==pnode)
	{
		return LINK_ERROR;
	}
	pnode->data=data;
	if(plink->pnext==NULL)
	{
		plink->pnext=pnode;
		pnode->plast=plink;
		pnode->pnext=plink;
		plink->plast=pnode;
	}
	else
	{
		pnode->pnext=plink->pnext;
		pnode->plast=plink;
		plink->pnext->plast=pnode;
		plink->pnext=pnode;
	}
	return LINK_OK;
} 

int deletelink(Data *plink,data_t *data)
{
	if(NULL==plink || data==NULL || plink->pnext==NULL)
	{
		return LINK_ERROR;
	}
	Data *pdel;  
	if(plink->pnext->pnext==plink)
	{
		pdel=plink->pnext;
		plink->plast=NULL;
		plink->pnext=NULL;
		*data=pdel->data;
		free(pdel);
		pdel=NULL;
	}
	else
	{               
		pdel=plink->pnext;
		plink->pnext=pdel->pnext;
		pdel->pnext->plast=plink;
		*data=pdel->data;
		free(pdel);
		pdel=NULL;
	}
	return LINK_OK;
}


int find(Data *plink,data_t data)
{
	if(NULL==plink)
	{
		return LINK_ERROR;
	}
	int i;
	Data *ptemp=plink->pnext;
	while(ptemp!=plink)
	{
		if(ptemp->data==data)
		{
			printf("%d",data);
			return LINK_OK;
		}
		ptemp=ptemp->pnext;
	}
	return LINK_OK;
}

int show(Data *plink)
{
	if(NULL==plink)
	{
		return LINK_ERROR;
	}
	Data *ptemp=plink->pnext;
	while(ptemp!=plink)
	{
		printf("%5d",ptemp->data);
		ptemp=ptemp->pnext;
	}
	return LINK_OK;
}
int destory(Data *plink)
{
	if(NULL==plink)
	{
		return LINK_ERROR;
	}
	Data *ptemp=plink->pnext;
	if(NULL!=ptemp)
	{
		plink->pnext=NULL;
		Data *pdel;
		while(ptemp!=plink)
		{
			pdel=ptemp;
			ptemp=ptemp->pnext;
			free(pdel);
			pdel=NULL;
		
		}
	}
	free(plink);
	plink=NULL;
	return LINK_OK;
}

