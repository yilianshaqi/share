#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"

	_I creat(Data * plist)

{

	plist->data=(int *)malloc(sizeof(_I)*LEN);

	if(NULL==plist->data)
	{
		return list_error;
	}
	memset(plist->data,0,sizeof(_I)*LEN);  
	
	return list_ok;
}



 _I leng=LEN;;

_I insert(Data *plist ,_I offset, _I data)
{
	if(NULL==plist || offset>plist->inum ||offset<0 ||plist->data==NULL)
	{
		return list_error;
	}
	_I i;
	
	if(leng ==plist->inum)
	{
		expand(plist);
		if(plist->data==NULL)
		return list_error;
	}    


	for(i=plist->inum-1;i>=offset;i--)
	{
		plist->data[i+1]=plist->data[i];
	}
	plist->data[offset]=data;
	plist->inum++;
	return list_ok;
}




_I delete(Data *plist, _I offset, _I *data)

{
	if(NULL==plist || offset>=plist->inum || offset<0 ||plist->data == NULL )
	{
		return list_error;
	}
	*data=plist->data[offset];
	_I i;
	for(i=offset;i<plist->inum-1;i++)
	{
		plist->data[i]=plist->data[i+1];
	}
	plist->inum--;
//	printf("Delete success");
	return list_ok;
}



_I find( Data * plist ,_I data)
{
	if(NULL==plist||plist->data == NULL )
	{
		return list_error;
	}
	U_I i;

	for(i=0;i<plist->inum;i++)
	{
		if(plist->data[i]==data)
		{
			printf("%d position=%4d\n",data,i);

			return list_ok;
		}
	}
	return list_error;
     
}



_I updata(Data * plist ,_I offset,_I data)

{
	if(NULL==plist || offset>= plist->inum || offset<0 ||plist->data == NULL)
	{
		return list_error;
	}
	plist->data[offset]=data;
	return list_ok;
}



void destroy(Data *plist)
{
	if(NULL==plist || plist->data == NULL)
	{
		return ;
	}
	free(plist->data);
	plist->data=NULL;
	return ;
}

_I show(Data *plist)
{
	if(NULL==plist)
	{
		return list_error;
	}
	U_I i;
	for(i=0;i<plist->inum;i++)
	{
		printf("%5d",plist->data[i]);
	}
	printf("\n");
	return list_ok;
}


