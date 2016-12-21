#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void menu(void)
{
	Data *list;
	list=creat();
	_I offset;
	_I data;
	U_I select;
	_I ret;
	_I loop=1;
	while(loop)
	{
 		printf("Please select options:\n");
		printf("%d-----------------insert data\n",insertdata);
		printf("%d-----------------find   data\n",finddata);
		printf("%d-----------------delete data\n",deletedata);
		printf("%d-----------------updata data\n",updatadata);
		printf("%d-----------------show   data\n",showdata);
		printf("%d-----------------esc        \n",esc);
		scanf("%d",&select);
	
	
		switch (select)
		{
			case insertdata:
					printf("please input insert position and data:\n");
					scanf("%d%d",&offset,&data);
					ret=insert(list,offset,data);
					if(ret==list_ok)
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
					ret=find(list,data);
					if(ret==list_ok)
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
					ret=delete(list,offset,&data);
					if(ret==list_ok)
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
					ret=updata(list,offset,data);
					if(ret==list_ok)
					{
						printf("Updata success\n");
					}
					else
					{	
						printf("Updata  failed\n");
					}
					break;
			case showdata:
					ret=show(list);
					if(ret==list_error)
					{
						printf("Show data failed\n");
					}
					break;
			case esc :
					destroy(list);
					loop=0;
					break;
			default :
					break;
		}
	}
}
