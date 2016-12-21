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
void *pthread_send(void * sfile)
{
	Search  file_mes;
	File_message *send_mes;
	send_mes=malloc(sizeof(File_message));
	if(send_mes==NULL)
	{
		perror("malloc ");
		return send_mes;
	}
	bzero(send_mes,sizeof(File_message));
	file_mes=*(Search *)sfile;
	int s_fd=socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in dest;
	bzero(&dest,sizeof(dest));
	dest.sin_family=AF_INET;
	dest.sin_port=htons(5000);
	inet_pton(AF_INET,"127.0.0.7",&dest.sin_addr);

	int ret=connect(s_fd,(struct sockaddr *)&dest,sizeof(struct sockaddr));
	if(ret<0)
	{
		perror("connect");
		pthread_exit(0) ;
	}
	int file=open(file_mes.name,O_RDONLY,0777);
	if(file<0)
	{
		perror("open file");
		pthread_exit(0);
	}
	lseek(file,file_mes.count*FILE_SIZE,SEEK_SET);
	strcpy(send_mes->name,file_mes.name);
	send_mes->count=file_mes.count;
	while(1)
	{	
		bzero(send_mes->buf,READ_SIZE);
		int ret=read(file,send_mes->buf,READ_SIZE);
	
		if(ret<=0)
		{
			pthread_exit(0);
		}
		send(s_fd,send_mes,sizeof(File_message),0);
	}
}

