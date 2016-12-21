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

int main()
{
	Data *buf=NULL;
	buf=(Data*)malloc(sizeof(Data));
	struct sockaddr_in dest;
	bzero(&dest,sizeof(dest));
	if(buf==NULL)
	{
		perror("malloc");
		return -1;
	}
	bzero(buf,BUF_SIZE);
	int c_fd=select_message(dest);
	if(c_fd<0)
	{
		perror("select_message");
		return -1;
	}
	int ret=recv(c_fd,buf,sizeof(Data),0);
	if(ret<0)
	{
		return -1;
	}
	if(ret==0)
	{
		close(i);
		FD_CLR(i,&list);
	}
	
	search_file(buf);
	send(c_fd,buf,sizeof(Data));
	int file=open(buf.data,O_RDONLY);
	while(1)
	{
		bzero(buf->data)
		ret=read(file,buf->data,BUF_SIZE);
		if(ret<=0)
		{
			return -1;
		}
		send(c_fd,buf,sizeof(Data));
	}
}
