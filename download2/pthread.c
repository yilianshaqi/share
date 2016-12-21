#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include<errno.h>
#include<sys/select.h>
#include <sys/stat.h>
#include <fcntl.h>

#include"head.h"

void *pthread_send(void * buf)
{
	Data file_send;
	bzero(&file_send,sizeof(Data));
	file_send=*(Data *)buf;
	int s_fd=socket(AF_INET,SOCK_STREAM,0);
	int ret=connect(s_fd,(struct sockaddr *)&file_send.dest,sizeof(struct sockaddr));
	if(ret<0)
	{
		perror("connect");
		pthread_exit(0) ;
	}
	int file=open(file_send.name,O_RDONLY,0777);
	if(file<0)
	{
		perror("open file");
		pthread_exit(0);
	}
	lseek(file,file_send.count*FILE_SIZE,SEEK_SET);
	printf("name =%s\n",file_send.name);
	send(s_fd,&file_send,sizeof(Data),0);
	while(1)
	{	
		bzero(file_send.data,READ_SIZE);
		int ret=read(file,file_send.data,READ_SIZE);
		if(ret<=0)
		{
			close(s_fd);
			pthread_exit(0);
		}
		send(s_fd,file_send.data,ret,0);
	}
}

