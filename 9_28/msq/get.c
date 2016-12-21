/*************************************************************************
    > File Name: get.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Wed 28 Sep 2016 01:10:09 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *line=NULL;
	FILE *fp;
	int len=0;
	int read;
	int size=0;
	int num=0;

	fp=fopen("/home/farsight/lianxi/kk","r");
	if(fp==NULL)
	{
		return -1;
	}
	while(feof(fp)==0)
	{
		size=ftell(fp);
		printf("size=%d\n",size);
		read=getline(&line,&len,fp);
		printf("%s\n",line);
		printf("read=%d\n",read);
		num++;
		printf("num=%d\n",num);
	}
	free(line);
	return 0;
}
