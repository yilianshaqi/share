#include"header.h"
#include<string.h>
#include<stdlib.h>
void add(data * array ,int set, char *pstr)
{
	if(strlen(pstr)+array->inum>LEN)
	{
		exit;			
	}
	int len;
	len=strlen(pstr);
	int i;
	for(i=array->inum-1;i>=set;i--)
	{
		array->str[i+len]=array->str[i];
	}
	for(i=set;i<set+len;i++)
	{
			array->str[i]=*pstr;
			pstr++;
	}
	array->inum=array->inum+len;
	array->str[array->inum]='\0';
}
