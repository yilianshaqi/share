#include<string.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include<errno.h>
#include<sys/select.h>
#include"head.h"

int search_file(Data * buf)
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
		if(strcmp(file->d_name,buf->data)==0)
		{
			ret=stat(file->d_name,filestat);
			if(ret != 0)
			{
				perror("readdir filestat");
				return -1;
			}
			bzero(buf,sizeof(Data));
			strcpy(buf->func,"answer");
			strcpy(buf->stat,"yes");
			strcpy(buf->data,filestat->st_size);
			return 0;
		}
	}
	return -1;
}
