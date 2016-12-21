/*************************************************************************
    > File Name: test.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Fri 23 Sep 2016 01:57:03 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[],char *env[])
{

	while(argc--)
	{

		printf("%s\r\n",*argv++);
	}
	printf("------------------------------------------\r\n");
	while(*env)
	{

		printf("%s\r\n",*env++);
	}
	printf("%s\r\n",getenv("PWD"));
	return 0;
}
		
