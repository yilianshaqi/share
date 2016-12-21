#include<stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include"ls.h"

 
int main()
{
	
	//open dir
	DIR *dir=opendir(".");

	if(NULL== dir)
	{
		perror("opendir");
		return -1;
	}
	//readdir file get filename
	struct dirent *file=NULL;
	struct stat *filestat=NULL;
	filestat=(struct stat *)malloc(sizeof(struct stat));
	if(NULL==filestat)
	{
		return -1;
	}
	memset(filestat,0,sizeof(struct stat));
	int ret;
	char *name=NULL;
	name=(char *)malloc(LEN);
	if(name==NULL)
	{
		return -1;
	}
	memset(name,0,LEN);
	while((file=readdir(dir) )!= NULL)
	{
		//get file stat
		ret=stat(file->d_name,filestat);
		if(ret != 0)
		{
			perror("readdir filestat");
			return -1;
		}
		memset(name,0,LEN);
		mode(filestat->st_mode,name);
		printf("%s ",name);
		memset(name,0,LEN);

		printf("%d ",filestat->st_nlink);
//		uid(filestat->st_uid,name);
		uid(filestat->st_uid);
//		printf("%s ",name);
//		memset(name,0,LEN);
		uid(filestat->st_gid);

//		uid(filestat->st_gid,name);
//		printf("%s ",name);
//		printf("%4ld ",filestat->st_size);
		memset(name,0,LEN);
		timetrans(name,&filestat->st_atime);
		printf("%s ",name);
		printf("%s\n",file->d_name);
	}
	//close dir
	closedir(dir);
	return -1;
}
