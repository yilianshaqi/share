
#include<stdlib.h>
#include"link.h"
int taildelete(Data * plink,data_t *data)
{
	if(plink==NULL || plink->pnext==NULL)
	{
		return LINK_ERROR;
	}
	Data *pdel;
	Data *ptemp=plink;
//	while(ptemp->pnext->pnext!=plink)
//	{
//		ptemp=ptemp->pnext;
//	}
	if(ptemp->plast->plast!=plink)
	{
		ptemp=ptemp->plast->plast;
		pdel=ptemp->pnext;
		ptemp->pnext=pdel->pnext;
		pdel->pnext->plast=ptemp;
		*data=pdel->data;
		free(pdel);
		pdel=NULL;
	}
	else
	{
		pdel=ptemp->pnext;
		ptemp->pnext=NULL;
		ptemp->plast=NULL;
		*data=pdel->data;
		free(pdel);
		pdel=NULL;
	}
	
	return LINK_OK;
}
