/*************************************************************************
    > File Name: daemon.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Mon 26 Sep 2016 01:39:33 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
int  main()
{
	//creat child process
	
	int  pid=0;
	pid=fork();
	int ret;
	if(-1==pid)
	{
		printf("creat fork error\n");
		return -1;
	}
	//kill parent process
	if(pid>0)
	{
		exit (0);
	}
	//create child process session
	sleep(30);
	ret=setsid();
	printf("%d\n",ret);
/*	
	if(ret==-1)
	{
		printf("setsid error\n");
		return -1;
	}
		*/
	//exchange directory
	if(-1==chdir("/"))
	{
		printf("chdir error\n");
		return -1;
	}
	//exchange mask
	creat("/home/farsight/huang.c",0777);
	umask(0077);
	creat("/home/farsight/yang.c",0777);
	
	//close fd
	ret=getdtablesize();
	int i=0;
	for(i=0;i<ret;i++)
	{
		close(i);
	}
	printf("creat daemon ok\n");
	sleep(200);
	return 0;
}
