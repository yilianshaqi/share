/*************************************************************************
    > File Name: open.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Wed 21 Sep 2016 08:31:30 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#define LEN 10
int main(int argc ,char *argv[])
{
	//check arguement 
	if(argc != 3)
	{
		printf("input error\n");
		return -1;
	}
	//open src
	int src=open(argv[1],O_RDWR);
	if(src<0)
	{
		perror("open file");
		return -1;
	}
	//open dest
	int dest=open(argv[2],O_WRONLY | O_CREAT |O_APPEND);
	if(dest<0)
	{
		perror("open file");
		return -1;
	}
	//read file
	//write file
	char buf[LEN]={0};
	while(1)
	{
		int read_size=0;
		int write_size=0;
		read_size=read(src,buf,LEN);
		if(read_size <=0)
		{
			break;
		}
		write_size=write(dest,buf,read_size);

	}
	//close src and dest
	close(src);	
	close(dest);
	return 0;
}
