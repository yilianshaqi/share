#include<stdio.h>
#include<stdlib.h>
#include"linkheader.h"

void menu(void)
{
	Link * linkhead;
	linkhead=creatlink();
	if(NULL==linkhead)
	{
		return ;
	}
	int offset;
	data_t data;
	int ret;
	int select;
	Link * ptail;
	while(1)
	{
 		printf("Please select options:\n");
		printf("%d-----------------insert data\n",insertdata);
		printf("%d-----------------find   data\n",finddata);
		printf("%d-----------------delete data\n",deletedata);
		printf("%d-----------------updata data\n",updatadata);
		printf("%d-----------------show   data\n",showdata);
		printf("%d-----------------rank  data\n",ranklink);
		printf("%d-----------------tail  data\n",linktail);
		printf("%d-----------------esc        \n",esc);
		scanf("%d",&select);
	
	
		switch (select)
		{
			case insertdata:
					printf("please input insert position and data:\n");
					scanf("%d%d",&offset,&data);
					ret=insertlink(linkhead,offset,data);
					if(ret==link_ok)
					{
						printf("Insert success\n");
					}
					else
					{	
						printf("insert  failed\n");
					}
					break;
			case finddata:
					printf("please input find data:\n");
					scanf("%d",&data);
					ret=find(linkhead,data);
					if(ret==link_ok)
					{
						printf("Find success\n");
					}
					else
					{	
						printf("No find\n");
					}
					break;
			case deletedata:
					printf("please input delete position a:\n");
					scanf("%d",&offset);
					ret=deletelink(linkhead,offset,&data);
					if(ret==link_ok)
					{
						printf("Delete success\n");
					}
					else
					{	
						printf("Delete  failed\n");
					}
					break;
			case updatadata:
					printf("please input updata position and data:\n");
					scanf("%d%d",&offset,&data);
					ret=updatalink(linkhead,offset,data);
					if(ret==link_ok)
					{
						printf("Updata success\n");
					}
					else
					{	
						printf("Updata  failed\n");
					}
					break;
			case showdata:
					ret=showlink(linkhead);
					if(ret==link_error)
					{
						printf("Show data failed\n");
					}
					break;
			case ranklink:
					ret=rank(linkhead);
					if(ret==link_ok)
					{
						printf("rank success\n");
					}
					else
					{	
						printf("rank  failed\n");
					}
					break;
			case linktail:
					
					ptail=findtail(linkhead);
					printf("%5d\n",ptail->data);
				
					break;
			case esc :
					destroy(linkhead);
					exit(0);
			default :
					break;
		}
	}
}

