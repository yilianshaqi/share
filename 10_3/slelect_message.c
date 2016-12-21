/*************************************************************************
    > File Name: select.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Fri 30 Sep 2016 12:50:23 AM PDT
 ************************************************************************/

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

int  select_message(struct sockaddr_in *dest)
{
	//
	struct sockaddr_in src;
	bzero(&src, sizeof(src));
	int len_src=sizeof(src);
	int len_dest=sizeof(struct sockaddr_in);
	src.sin_family=AF_INET;
	src.sin_port=htons(port);
	inet_pton(AF_INET,"127.0.0.10",&src.sin_addr);

	int s_fd=socket(AF_INET,SOCK_STREAM,0);
	if(s_fd <0)
	{
		perror("socket  ");
		return -1;
	}
	int ret=bind(s_fd , (struct sockaddr *)&src ,len_src );
	if(ret <0)
	{
		perror("socket  ");
		return -1;
	}
	ret=listen(s_fd,10);
	if(ret<0)
	{
		perror("listen ");
		return -1;
	}
	int nfd=0;
	fd_set list;
	fd_set templist;
	bzero(&list ,sizeof(list));
	FD_SET(s_fd,&list);
	nfd=nfd<s_fd ? s_fd : nfd ;
	int i=0;
	int c_fd=-1;
	while(1)
	{
		templist=list;
		ret=select(nfd+1,&templist,NULL,NULL,NULL);
		if(ret<0)
		{
			perror("select ");
			return -1;
		}
	for(i=0;i<nfd+1;i++)
	{
		if(FD_ISSET(i,&templist))
		{
			if(i==s_fd)
			{
				c_fd=accept(s_fd,(struct sockaddr *)dest,&len_dest);
				FD_SET(c_fd ,&list);
				nfd=nfd>c_fd ? nfd : c_fd ;
			}
			else
			{	
				
				return i;
				       
			}
		}
	}
	}
}

