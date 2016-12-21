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
#include <pthread.h>
#include"head.h"


int main()
{
	char  buf[BUF_SIZE]="";
	Search sfile;
	bzero(&sfile,sizeof(sfile));
	struct sockaddr_in src,dest;
	bzero(&src,sizeof(src));
	bzero(&dest,sizeof(dest));
	int len_dest=sizeof(dest);
	src.sin_family=AF_INET;
	src.sin_port=htons(6000);
	inet_pton(AF_INET,"127.0.0.9",&src.sin_addr);
	int s_fd=socket(AF_INET,SOCK_STREAM,0);
	if(s_fd<0)
	{
		perror("socket");
		return -1;
	}
	int ret=bind(s_fd,(struct sockaddr *)&src,sizeof(src));
	if(ret<0)
	{
		perror("bind");
		return -1;
	}
	listen(s_fd,10);
	fd_set list;
	fd_set templist;
	bzero(&list,sizeof(list));
	bzero(&templist,sizeof(templist));
	FD_SET(s_fd,&list);
	int nfd=0;
	int i=0;
	nfd=nfd<s_fd ? s_fd : nfd ;
	while(1)
	{
		templist=list;
		select(nfd+1,&templist,NULL,NULL,NULL);
		for(i=0;i<=nfd;i++)
		{
			if(FD_ISSET(i,&templist))
			{
				if(i==s_fd)
				{
					int c_fd=accept(s_fd,(struct sockaddr *)&dest,&len_dest);
					FD_SET(c_fd,&list);
					nfd=nfd<c_fd ? c_fd : nfd ;
				}
				else 
				{
					ret=recv(i,buf,BUF_SIZE,0);
					if(ret<0)
					{
						FD_CLR(i,&list);
						return -1;
					}
					if(ret==0)
					{
						close(i);
						FD_CLR(i,&list);
						return -1;
					}
					strcpy(sfile.name,buf);
					search_file( &sfile);
					send(i,&sfile,sizeof(sfile),0);
					int n=sfile.data/FILE_SIZE;
					int i;
					pthread_t pthread=0;
					sfile.dest=dest;
					printf("addr=%s\n",(char *)&dest.sin_addr);
					printf("port=%d",dest.sin_port);
				//if panduan	
					for(i=0;i<=n;i++)
					{	
						sfile.count=i;
						
						pthread_create(&pthread,NULL,pthread_send,(void *)&sfile);
						pthread_detach(pthread);
						
					}
				}
			}
		}
	}
}
