#include<stdio.h>
#include"linkheader.h"

Link * recursive(Link *plink)
{
	
	if(NULL==plink->next)
	{
		return plink;
		
	}
	return recursive(plink->next);
}

Link * findtail(Link * plink)
{
	if(NULL==plink)
	{
		return plink;
	}
	
	Link * ptemp=plink;
	Link * ptail=recursive(ptemp);
	
	return ptail;
}
