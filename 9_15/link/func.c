#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"
Data *creation(void)
{
	Data *plink=NULL;
	plink=(Data *)malloc(sizeof(Data));
	if(NULL==plink)
	{
		return plink;
	}
	memset(plink,0,sizeof(Data));
	return plink;	
}
/*
int insert(Data *plink,int offset,  data_t data)
{
	if(NULL==plink || offset<0)
	{
		return LINK_ERROR;
	}
	Data *pnew;
	pnew=creation();
	if(pnew==NULL)
	{
		return LINK_ERROR;
	}
	int i;
	Data *ptemp=plink;
	for(i=0;i<offset;i++)
	{
		if(ptemp->pnext != NULL)
		{
			ptemp=ptemp->pnext;
		}
	}
	pnew->pnext=ptemp->pnext;
	ptemp->pnext=pnew;
	pnew->data=data;       
///////////////////////////////////////////////////////////
//	if(pnew->pnext==NULL)
//	{
//		plink->data=(data_t )pnew;
//		printf("ok");
//	}
	
////////////////////////////////////////////////////////////
	return LINK_OK;    	
}  */
	int insert(Data * plink ,int offset,data_t data)
	{
		if(NULL==plink )
		{
			return LINK_ERROR;
		}
		Data *pnode;
		Data *ptemp=plink;
		pnode=creation();
		if(NULL==pnode)
		{
			return LINK_ERROR;
		
		}
		switch(offset)
		{
			case header:
				pnode->pnext=plink->pnext;
				plink->pnext=pnode;
				pnode->data=data;
				if(pnode->pnext == NULL)
				{
					plink->data=(data_t )pnode;
					printf("ok");
				}
				break;
			case tail:
				ptemp=(Data *)plink->data;
				ptemp->pnext=pnode;
				pnode->data=data;
				plink->data=(data_t)pnode;
				printf("ok");
				break;
			default:
				while(offset--)
				{
					
					if(NULL!=ptemp->pnext)
					{
						ptemp=ptemp->pnext;
						
					}
					
				}
				pnode->pnext=ptemp->pnext;
				ptemp->pnext=pnode;
				pnode->data=data;
				if(pnode->pnext == NULL)
				{
					plink->data=(data_t )pnode;
					printf("ok");
				}
		}
		return LINK_OK;
		
	}



int delete(Data *plink,int offset,data_t *data)
{
	if(NULL==plink || offset <0 )
	{
		return LINK_ERROR;
	}
	int i;
	Data *ptemp=plink;
	Data *pdel;
	if(plink->pnext != NULL)
	{	
		for(i=0;i<offset;i++)
		{
			if(ptemp->pnext->pnext != NULL)
			{
				ptemp=ptemp->pnext;
			}
		}
		pdel=ptemp->pnext;
		ptemp->pnext=pdel->pnext;
		*data=pdel->data;
		free(pdel);
	}       
//////////////////////////////////////////////////////
	if(ptemp->pnext==NULL)
	{
		plink->data=(data_t )ptemp;
		printf("ok");
	}
	
/////////////////////////////////////////////////////	
	return LINK_OK;	 
}     



int updata(Data *plink,int offset,data_t data)
{
	if(NULL==plink || offset<0 )
	{
		return LINK_ERROR;
	}
	int i;
	plink=plink->pnext;
	for(i=0;i<offset;i++)
	{
		if(plink->pnext!=NULL)
		{
			plink=plink->pnext;
		}
	}
	plink->data=data;
	return LINK_OK;
}


int find(Data *plink ,data_t data)
{
	if(NULL==plink)
	{
		return LINK_ERROR;
	}
	int i=1;
	plink=plink->pnext;
	while(plink != NULL)
	{	
		if(plink->data==data)
		{
			printf("%d position= %d",data,i);
			return LINK_OK;
		}
		plink=plink->pnext;
		i++;
	}
	return ;
}
int show (Data *plink)
{
	if(NULL==plink)
	{
		return LINK_ERROR;
	}
	plink=plink->pnext;
	while(plink!=NULL)
	{
		
		printf("%d\t",plink->data);
		plink=plink->pnext;
	}
	printf("\n");
	return LINK_OK;
}

int destory(Data *plink)
{
	if(NULL==plink)
	{
		return LINK_ERROR;
	}
	Data *ptemp;
	Data *pdel;
	while(plink->pnext->pnext!=NULL)
	{
		for(ptemp=plink;ptemp->pnext->pnext!=NULL;ptemp=ptemp->pnext);
		pdel=ptemp->pnext;
		ptemp->pnext=NULL;
		free(pdel);
	}
	pdel=plink->pnext;
	free(pdel);
	free(plink);
	return LINK_OK;
}



