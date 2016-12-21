/*************************************************************************
    > File Name: dayfseek.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Wed 21 Sep 2016 04:50:05 AM PDT
 ************************************************************************/

#include<stdio.h>
#define LEN 10
int main()
{
//	if(argc !=2)
//	{
//		printf("INPUT ERROR\n");
//		return -1;
//	}
	FILE *file=fopen("3.txt","r+");
	if(NULL==file)
	{
		perror("open file");
		return -1;
	}
	char string[LEN];
	int ret;
	printf("position=%ld\n",ftell(file));
	ret=fread(string,sizeof(char),2,file);
	printf("%s\n",string);
	printf("position=%ld\n",ftell(file));

	fseek(file,6,SEEK_CUR);
	ret=fread(string,sizeof(char),3,file);
	printf("%s\n",string);
	
	printf("position=%ld\n",ftell(file));
	fseek(file,8,SEEK_END);
	ret=fwrite(string,sizeof(char),4,file);
//	printf("%s\n",string);
	printf("position=%ld\n",ftell(file));
	return -1;
}
