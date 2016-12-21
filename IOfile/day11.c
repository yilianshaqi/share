/*************************************************************************
    > File Name: day11.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Wed 21 Sep 2016 04:03:43 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#define STRING_SIZE 10
int main()
{
	FILE *file=fopen("1.txt","r");
	if(NULL==file)
	{
		perror("open file");
		return -1;
	}
	char string[STRING_SIZE]={0};
//	fread(string,sizeof(char),8,file);
//	fgets(string,8,file);
//	fgets(string,5,stdin);
	printf("hellow world");
	fflush(stdout);
//	printf("%s\n",string);
	usleep(8000000);
	return -1;
}
