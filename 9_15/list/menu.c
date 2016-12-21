#include<stdlib.h>
#include<stdio.h>
#include"header.h"
void menu(void)
{
	Data *list;
	list=create();
	int offset;
	data_t data;
	int ret,option;
	while(1)
	{
		printf("%d************************INSERT\n",INSERT);
		printf("%d************************DELETE\n",DELETE);
		printf("%d************************FIND\n",FIND);
		printf("%d************************UPDATA\n",UPDATA);
		printf("%d************************SHOW\n",SHOW);
		printf("%d************************ESC\n",ESC);
		scanf("%d",&option);
		switch(option)
		{
			case INSERT :
				printf("input position and data\n");
				scanf("%d%d",&offset,&data);
				ret=insert(list,offset,data);
				if(ret==LIST_ERROR)
				{
					printf("INPUT ERROR\n");
				}
				else
				{
					printf("SUCCED\n");
				}
				break;
			case FIND :
				printf("input data");
				scanf("%d",&data);
				ret=find(list,data);
				if(ret==LIST_ERROR)
				{
					printf("INPUT ERROR\n");
				}
				else if(ret==NO_DATA)
				{
					printf("NO FIND\n");
				}
				else
				{
					printf("SUCCED\n");
				}
				break;
			case DELETE :
				printf("input position\n");
				scanf("%d",&offset);
				ret=delete(list,offset,&data);
				if(ret==LIST_ERROR)
				{
					printf("INPUT ERROR\n");
				}
				else
				{
					printf("SUCCED\n");
				}
				break;
			case UPDATA :
				printf("input position and data\n");
				scanf("%d%d",&offset,&data);
				ret=updata(list,offset,data);
				if(ret==LIST_ERROR)
				{
					printf("INPUT ERROR\n");
				}
				else
				{
					printf("SUCCED\n");
				}
				break;
			case SHOW :
				ret=show(list);
				if(ret==LIST_ERROR)
				{
					printf("INPUT ERROR\n");
				}
				else
				{
					printf("SUCCED\n");
				}
				break;
			case ESC :
				exit(0);
				break;
			default :
				break;
		}
	}
}
