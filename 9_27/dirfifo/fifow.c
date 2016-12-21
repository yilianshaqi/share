/*************************************************************************
    > File Name: fifow.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Mon 26 Sep 2016 08:14:51 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>

int main()
{
	// creat fifo
	int ret = 0;
	ret = mkfifo("fifo",0664);
	if(ret<0&& EEXIST!=errno)
	{
		perror("mkfifo");
		return -1;
	}
	printf("create fifo ok\n");
	//open fifo
	int fd=-1;
	fd=open("fifo",O_WRONLY);
	if(fd<0)
	{
		perror("open fifo");
		return -1;
	}
	printf("open fifo ok\n");
	//write data to fifo
	char buf[]={"hello hy"};
	write(fd,buf,sizeof(buf));
	printf("write data to fifo ok]n");
	close(fd);
	return 0;

}
