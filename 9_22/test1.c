/*************************************************************************
    > File Name: test1.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Fri 23 Sep 2016 02:02:06 AM PDT
 ************************************************************************/

#include<stdio.h>
int main()
{
	char *p[]={"hello"," world","!"};
	int i=3;
	while(i--)
	{
		printf("%s\n",*p++);
	}
	return 0;
}
