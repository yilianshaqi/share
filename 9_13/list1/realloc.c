#include<stdlib.h>
#include<stdio.h>
#include"header.h"


void expand(Data * plist)
{
	static len=LEN;
	len+=LEN;
	int ret;


	plist->data=(int *)realloc(plist->data,len*sizeof(int));
/*	return p;
	int i;
	
	printf("ok...%d\n",plist->inum);
	plist->inum=ret;
	for(i=0;i<plist->inum;i++)
	{
		printf("%5d",plist->data[i]);
	}    */
}
