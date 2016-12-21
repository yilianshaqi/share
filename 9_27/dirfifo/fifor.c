/*************************************************************************
    > File Name: fifor.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Mon 26 Sep 2016 10:14:38 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#define BUF_SIZE 10
int main()
{
	//create fifo
	int ret=0;
	ret=mkfifo("fifo",0666);
	if(ret<0&&EEXIST!=errno)
	{

		perror("mkfifo");
		return -1;
	}
	printf("creat fifo ok\n");
	//open fifo 
	int fd=-1;
	fd=open("fifo",O_RDONLY);
	if(fd<0)
	{
		perror("open fifo");
		return -1;
	}
	printf("open fifo ok\n");
	//read fifo 
	char buf[BUF_SIZE]={0};
	printf("before read\n");
	read(fd,buf,BUF_SIZE);
	printf("after read\n");
	printf("%s\n",buf);
	//close fifo
	close(fd);
	return 0;
}
