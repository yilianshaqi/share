#include<stdio.h>
#include"linkheader.h"


int insertlink(Link * plink ,int offset,data_t data)
{
	if(NULL==plink)
	{
		return link_error;
	}
	Link *pnode;
	pnode=creatlink();
	switch(offset)
	{
		case header:
			pnode->next=plink->next;
			plink->next=pnode;
			pnode->data=data;
			break;
		case tail:
			plink=findtail(plink);
			plink->next=pnode;
			pnode->data=data;
			break;
		default:
			while(offset--)
			{
				if(NULL!=plink->next)
				{
					plink=plink->next;
				}
				else
					break;
			}
			pnode->next=plink->next;
			plink->next=pnode;
			pnode->data=data;
			
	}
	return link_ok;
	
}
