#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"headerfile.h"

int addbook(void)
{
	int i;
	for(i=0;num[i]!=NULL;++i);//�ҵ����������Ϣ�Ŀ�λ
	//Ϊ��λ�����ڴ�ռ����������Ϣ
	num[i]=(book *)malloc(sizeof(book));
	if(num[i]==NULL)
	{
		return -1;		
	}
	memset(num[i],0,sizeof(book));
	//��ʾ��¼����Ϣ
	int ret;
	printf("please iput book`s name:\n");
	scanf("%29s",num[i]->name);
	printf("input author:\n");
	scanf("%19s",num[i]->author);
	printf("input version date:\n");
	ret=scanf("%d%d%d",&num[i]->version.year,&num[i]->version.month,&num[i]->version.day);
	if(ret!=3)
	{
		printf("input error! please input again:\n");
		return -1;
	}

	printf("input publish:\n");
	scanf("%29s",num[i]->publish);
	printf("input abstract:\n");
	scanf("%199s",num[i]->abstract);
	
}
