
#include<stdio.h>
#include"linkheader.h"
int rank(Link * plink)
{
	if(NULL==plink)
	{
		return link_error;
	}
	Link *ptemp;
	Link *compare1;
	Link *compare2;
	
	int len;
	len=lengthlink(plink);
	int i,j;
	for(i=0;i<len-1;i++)
	{
		ptemp=plink;
		for(j=0;j<len-1-i;j++)
		{
			 compare1=ptemp->next;
			 compare2=ptemp->next->next;
			 if(compare1->data > compare2->data)
			 {
			 	ptemp->next=compare2;
			 	compare1->next=compare2->next;
			 	compare2->next=compare1;
			 }
			 ptemp=ptemp->next;
			 
		}
	}
//	showlink( plink);
	return link_ok;
}  
