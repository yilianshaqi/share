/*************************************************************************
    > File Name: day1.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Tue 20 Sep 2016 07:22:42 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

#define LEN 10
int main(int argc,char *argv[])
{
	if(argc != 3 )
	{
		printf("input error\n");
		return -1 ;
	}
	FILE *file=fopen(argv[1],"r");
	if(NULL==file)
	{
		perror("open file");
		return -1;
	}
	FILE *dest=fopen(argv[2],"w");
	if(NULL==dest)
	{
		perror("open dest");
		return -1;
	}
	char exchange[LEN]={0};
	while (!feof(file))
	{
		int ret=fread(exchange,sizeof(char),3,file);
		if(0==ret || ferror(file))
		{
			perror("fread");
			break;
		}
		fwrite(exchange,sizeof(char),ret,dest);
	}
	fclose(file);
	fclose(dest);
	return -1;
}
