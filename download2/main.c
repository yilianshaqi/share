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
	struct sockaddr_in src,dest;
	bzero(&dest,sizeof(dest));
	int len_dest=sizeof(dest);
	bzero(&src,sizeof(src));
	src.sin_family=AF_INET;
	src.sin_port=htons(6000);
	inet_pton(AF_INET,"127.0.0.11",&src.sin_addr);

	Data buf;
	bzero(&buf,sizeof(Data));

	int s_fd=socket(AF_INET,SOCK_STREAM,0);
	if(s_fd<0)
	{
		perror("socket");
		return -1;
	}
	bind(s_fd,(struct sockaddr *)&src,sizeof(src));
	listen(s_fd,10);
	fd_set list,templist;
	bzero(&list,sizeof(list));
	bzero(&templist,sizeof(templist));
	int nfd=0;
	FD_SET(s_fd,&list);
	nfd=nfd<s_fd ? s_fd : nfd ;
	int i;
	while(1)
	{
		printf("again\n");
		templist=list;
		select(nfd+1,&templist,NULL,NULL,NULL);
		printf("select ok\n");
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
					int ret=recv(i,&buf,sizeof(Data),0);
					if(ret<0)
					{
						FD_CLR(i,&list);
						perror("recv ");
						return -1;
					}
					if(ret==0)
					{
						FD_CLR(i,&list);
						return -1;
					}
		//			buf.dest=dest;

					printf("get file name\n");
					search_file(&buf);
					send(i,&buf,sizeof(Data),0);
					if(strcmp(buf.state,"yes")!=0)
					{	
						printf("no find file\n");
						continue;
					}
					
					recv(i,&buf,sizeof(Data),0);
					int n,i;
					n=buf.file_size/FILE_SIZE;
					pthread_t pthread;
					for(i=0;i<=n;i++)
					{
						buf.count=i;
						pthread_create(&pthread,NULL,pthread_send,(void *)&buf);
						printf("create pthread ok \n");
						pthread_detach(pthread);
					}
					
					
				}
			}
		}
	}
	
}


