/*************************************************************************
    > File Name: client.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Sat 01 Oct 2016 08:29:43 PM PDT
 ************************************************************************/

#include<stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<errno.h>
#define BUF_SIZE 30
int main()
{
	struct sockaddr_in dest;
	bzero(&dest,sizeof(dest));

	dest.sin_family=AF_INET;
	dest.sin_port=htons(6000);
	inet_pton(AF_INET,"127.0.0.10",&dest.sin_addr);
	int s_fd=-1;

	s_fd=socket(AF_INET,SOCK_STREAM,0);
	if(s_fd<0)
	{
		perror("socket");
		return -1;
	}
	int ret=connect(s_fd,(struct sockaddr *)&dest,sizeof(dest));
	if(ret<0)
	{
		perror("connect");
		return -1;
	}
	char buf[BUF_SIZE]="";
	while(1)
	{
		bzero(buf,BUF_SIZE);
		fgets(buf,BUF_SIZE,stdin);
		send(s_fd,buf,BUF_SIZE,0);

	}
	close(s_fd);
	return 0;
}
