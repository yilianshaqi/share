/*************************************************************************
    > File Name: FILEtest.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Wed 21 Sep 2016 03:09:48 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 10
int main()
{
	FILE *file=fopen("1.txt","r");
	if(NULL == file )
	{
		perror("fopen :");
		return -1;
	}
	printf("%p,%d\n",file,sizeof(FILE));
	printf("%p,%s\n",file->_IO_buf_base,file->_IO_buf_base);
	printf("%p,%p\n",file->_IO_buf_base,file->_IO_buf_end);
	char string[LEN];
	fread(string,sizeof(char),8,file);
	printf("%p,%d\n",file,sizeof(FILE));
	printf("%p,%s\n",file->_IO_buf_base,file->_IO_buf_base);
	printf("%p,%p\n",file->_IO_buf_base,file->_IO_buf_end);
	char *p=(char *)malloc(4096);
	if(NULL == p)
	{
		return -1;
	}
	memset(p,0,1024);
	*p='y';
	setbuf(file,p);
	printf("%p,%d\n",file,sizeof(FILE));
	printf("%p,%s\n",file->_IO_buf_base,file->_IO_buf_base);
	printf("%p,%p\n",file->_IO_buf_base,file->_IO_buf_end);
	return ;
}
