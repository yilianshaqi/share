/*************************************************************************
    > File Name: popen.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Sat 08 Oct 2016 09:41:56 PM PDT
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include<errno.h>
#include<string.h>
int main()
{
	FILE *file;
	char command[10]="";
	char buf[1024]="";
	strcpy(command, "ls");

	file=popen("ls /home/farsight", "r");
	if(file == NULL)
	{
		perror("popen ");
		return -1;
	}
/*	FILE *new;
	new=fopen("new","r+");
	if(new<0)
	{
		perror("fopen new");
		return -1;
	}   */
	fwrite(buf,sizeof(char),sizeof(buf),file);
	printf("%s\n",buf);
	pclose(file);
	return 0;
}
