#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"ls.h"
#include<string.h>

int timetrans(char *name, long int *t)
{
	struct tm *ptm=NULL;
	ptm=localtime(t);
	char *format=(char *)malloc(LEN);
	if(format==NULL)
	{
		return -1;
	}
	memset(format,0,LEN);
	strcpy(format,"%b %e %R");
	if(NULL==ptm)
	{
		perror("time ");
		return -1;
	}
	if(strftime(name,LEN,format,ptm )==0);
	
	{
	
		return -1;
	}
	return 0;
}

