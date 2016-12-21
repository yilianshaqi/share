#include<stdio.h>
#include<string.h>
#include "headerfile.h"
int findbook(void)
{
	
	printf("please input book`s name:\n");
	char name[30]={0};
	scanf("%29s",name);
	int i;
	for(i=0;i<NUM;++i)
	{
		if(num[i]!=NULL)
		{
			if(strcmp(num[i]->name,name)==0)
			{
				printf("%s\n%s\n",num[i]->name,num[i]->author);
				printf("version%d-%d-%d\n",num[i]->version.year,num[i]->version.month,num[i]->version.day);
				printf("%s\n%s\n",num[i]->publish,num[i]->abstract);
				return -1;	
			}
		}
		if(i==(NUM-1))
		{
			printf("no find %s \n",name);
			return -1;
		}
	}
}
