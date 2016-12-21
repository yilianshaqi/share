/*************************************************************************
    > File Name: echo.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Sat 08 Oct 2016 10:18:39 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int file=open("new",O_CREAT|O_RDWR,0777);
	if(file<0)
	{
		perror("opne new");
		return -1;
	}
	system("ls > new ");
	char buf[255]="";
	while(read(file,buf,255))
	{	
		printf("%s\n",buf);
	}
	close(file);
	return 0;
}
