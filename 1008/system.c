/*************************************************************************
    > File Name: system.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Sat 08 Oct 2016 09:13:06 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
	char buf[50]="";
//	strcpy(buf,"cd ");
	strcat(buf,"/home/farsight");
	chdir(buf);
//	printf("dangjianmulu = %s\n",getcwd(NULL,NULL));
	system("ls");
	printf("system ls");
	return  0;
	

	
}
