#include<stdio.h>
#include"link.h"
int main()
{
	Data *link;
	link=creatlink();
	if(NULL==link)
	{
		return ;
	}
	int i;
	data_t data;
	for(i=0;i<10;i++)
	{
		insertlink(link,i+20);
	}
	find(link,22);
	printf("\n");
	show(link);
	printf("\n");
	for(i=0;i<19;i++)
	{
		taildelete(link,&data);
		printf("%5d",data);
	}
	printf("\n");
	destory(link);
	return ;
}
