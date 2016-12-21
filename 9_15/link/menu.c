#include<stdlib.h>
#include<stdio.h>
#include"header.h"
void menu(void)
{
	Data *linkhead;
	linkhead=creation();
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
				ret=insert(linkhead,offset,data);
				if(ret==LINK_ERROR)
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
				ret=find(linkhead,data);
				if(ret==LINK_ERROR)
				{
					printf("INPUT ERROR\n");
				}
				else if(ret==LINK_OK)
				{
					printf("SUCCED\n");
				}
				else
				{
					printf("NO FIND\n");
				}
				break;
			case DELETE :
				printf("input position\n");
				scanf("%d",&offset);
				ret=delete(linkhead,offset,&data);
				if(ret==LINK_ERROR)
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
				ret=updata(linkhead,offset,data);
				if(ret==LINK_ERROR)
				{
					printf("INPUT ERROR\n");
				}
				else
				{
					printf("SUCCED\n");
				}
				break;
			case SHOW :
				ret=show(linkhead);
				if(ret==LINK_ERROR)
				{
					printf("INPUT ERROR\n");
				}
				else
				{
					printf("SUCCED\n");
				}
				break;
			case ESC :
				destory(linkhead);
				exit(0);
				break;
			default :
				break;
		}
	}
}

