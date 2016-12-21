/*************************************************************************
  > File Name: test.c
  > Author: huang yang
  > Mail: huangyangwork@sina.com 
  > Created Time: 2016年11月21日 星期一 22时07分54秒
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
#define BUF_SIZE   20
int main()
{
	int fd=open("/dev/test_dev",O_RDWR);
	if(fd<0)
	{
		perror("open error:\n");
		return -1;
	}
	char buf[BUF_SIZE]="";
	printf("before read \n");
	read(fd,buf,BUF_SIZE);
	printf("read:%s\n",buf);
	strcpy(buf,"hello world");
	write(fd,buf,strlen(buf));
	printf("write over\n");
	close(fd);
	return 0;
}
