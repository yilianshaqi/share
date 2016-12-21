#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkheader.h"

Link * creatlink(void)
{
	Link * link;
	link=(Link * )malloc(sizeof(Link));
	if(NULL==link)
	{
		return link;
		
	}
	memset(link,0,sizeof(Link));
	return link;
}



int insertlink(Link *plink,int offset ,data_t data)
{
	if(NULL==plink || offset<0)
	{
		return link_error;
	}
	Link * ptemp;
	Link * pnode;
	pnode=creatlink();
	if(NULL==pnode)
	{
		return link_error;
	}
	ptemp=plink;
	while(offset--)
	{
		if(ptemp->next!=NULL)
		{
			ptemp=ptemp->next;
		}
	}
	pnode->next=ptemp->next;
	ptemp->next=pnode;
	pnode->data=data;
	return link_ok;
}



/*
int deletelink(Link * plink ,int offset ,data_t * data)
{
	if(NULL==plink || offset<=0)
	{
		return link_error;
	}
	Link * ptemp;
	Link * pdel;
	ptemp=plink;
	if(ptemp->next==NULL)
	{
		return ;
	}
	for(;offset>0;offset--)
	{
		if(ptemp->next->next != NULL)
		{
			ptemp=ptemp->next;
		}
		else
		{
			if(offset==1)
			{
				pdel=ptemp->next;
				ptemp->next=pdel->next;
				*data=pdel->data;
				free(pdel);
				pdel=NULL;
				return link_ok;
			}
			else
				return link_error;
		}
	}
	pdel=ptemp->next;
	ptemp->next=pdel->next;
	*data=pdel->data;
	free(pdel);
	pdel=NULL;
	return link_ok;
}
*/

int deletelink(Link * plink ,int offset ,data_t *data)
{
	if(NULL==plink || offset<0 || plink->next==NULL)
	{
		return link_error;
	}
	Link * ptemp;
	Link * pdel;
	ptemp=plink;
	
	for(;offset>0;offset--)
	{
		ptemp=ptemp->next;
		if(ptemp->next==NULL)
		{
			return DELETE_FALSE;
		}
	}
	pdel=ptemp->next;
	ptemp->next=pdel->next;
	*data=pdel->next;
	free(pdel);
	pdel=NULL;
	return DELETE_OK;
}






int updatalink(Link * plink ,int offset , data_t data)
{
	if(NULL==plink || offset<=0)
	{
		return link_error;
	}
	Link * ptemp;
	ptemp=plink;
	while(offset--)
	{
		if(ptemp!=NULL)
		{
			ptemp=ptemp->next;
		}
		else
		{
			return link_error;
		}
	}
	ptemp->data=data;
	return link_ok;
	
}





int showlink(Link * plink )
{
	if(NULL==plink)
	{
		return link_error;
	}
	Link * ptemp;
	ptemp=plink->next;
	while(NULL!=ptemp)
	{
		printf("%5d",ptemp->data);
		ptemp=ptemp->next;
	}
	printf("\n");
	return link_ok;
}



int destroy(Link * plink)
{
	if(NULL==plink)
	{
		return link_error;
		
	}
	Link * ptemp;
	Link * pdel;
	ptemp=plink->next;
	while(ptemp!=NULL)
	{
		pdel=ptemp->next;
		free(ptemp);
		ptemp=pdel;
	}
	free(plink);
	plink=NULL;
	return link_ok;
}

int find(Link *plink, data_t data)
{
	if(NULL==plink)
	{
		return link_error;
	}
	Link * ptemp;
	ptemp=plink->next;
	while(ptemp!=NULL)
	{
		if(ptemp->data==data)
		{
			printf("%5d\n",ptemp->data);
			return link_ok;
		}
		ptemp=ptemp->next;
	}
	return link_error;
}

