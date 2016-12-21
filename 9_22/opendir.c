/*************************************************************************
    > File Name: opendir.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Wed 21 Sep 2016 11:30:29 PM PDT
 ************************************************************************/

#include<stdio.h>
#include <dirent.h>
#include <dirent.h>

int main()
{
	DIR *dir=opendir("/mnt/hgfs/share/");
	if(NULL==dir)
	{
		return -1;
	}
//	struct dirent *pp=readdir(dir);
	struct dirent *pp=NULL;
	while((pp=readdir(dir))!=NULL)
	{
		printf("%s\n",pp->d_name);
	}
	closedir(dir);
	return 0;
}
