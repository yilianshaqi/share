#include<stdio.h>
#include"linkheader.h"
int lengthlink(Link * plink)
{
	if(NULL==plink)
	{
		return link_error;
	}
	int len=0;
	Link * ptemp;
	ptemp=plink->next;
	
	while(ptemp!=NULL)
	{
		len++;
		ptemp=ptemp->next;
	}
	return len;
}

