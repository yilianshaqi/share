#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"headerfile.h"

int deletebook(void)
{
	printf("please input book`name:\n");
	char name[30]={0};
	scanf("%29s",name);
	int i;
	for(i=0;i<NUM;++i)
	{
		if(num[i]!=NULL)
		{
			if(strcmp(name,num[i]->name)==0)
			{
				printf("start");
				memset(num[i],0,sizeof(book));
				free(num[i]);
				num[i]=NULL;
				printf("ok");
				return -1;
			}
		}
		if(i==NUM-1)
		{
			printf("no find %s \n",name);
			return -1;
		}
	}
	
}
