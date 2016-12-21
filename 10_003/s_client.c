#include<stdio.h>
#include<netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>			
#include <sys/socket.h>
#include<string.h>
#include <pthread.h>
#include <stdlib.h>


#define FILE_SIZE 204800000

#define READ_SIZE 4096

typedef struct FILE_MESSAGE
{
	char name[20];
	int count ;
	char buf[READ_SIZE];
}File_message;
typedef struct SEARCH
{
	char name[20];
	char state[10];
	double data;
	int count;
	struct sockaddr_in dest;
}Search;


#define NAME_BUF_SIZE 30
void * pthread_recv(void * fd)
{
	int c_fd=*(int *)fd;
	File_message *file_mes; 
	file_mes=(File_message *)malloc(sizeof(File_message));
	if(file_mes==NULL)
	{
		perror("malloc");
		return file_mes;
	}
	bzero(file_mes,sizeof(File_message));
	recv(c_fd,file_mes,sizeof(File_message),0);
	
	int file=open(file_mes->name,O_WRONLY|O_CREAT,0777);
	if(file<0)
	{
		perror("client open file");
		pthread_exit(0);
	}
	lseek(file,file_mes->count*FILE_SIZE,SEEK_SET);
	while(1)
	{
	
		write(file,file_mes->buf,READ_SIZE);
		bzero(file_mes,sizeof(File_message));
		int ret=recv(c_fd,file_mes,sizeof(File_message),0);
		if(ret<=0)
		{	
			free(file_mes);
			pthread_exit(0);
		}
	}
	
}
int main()
{
	Search name_buf;
	bzero(&name_buf,sizeof(Search));
	struct sockaddr_in dest,src,temp;
	int len_temp=sizeof(temp);
	bzero(&src,sizeof(src));
	bzero(&temp,sizeof(temp));
	bzero(&dest,sizeof(dest));
	dest.sin_family=AF_INET;
	dest.sin_port=htons(6000);
	inet_pton(AF_INET,"127.0.0.9",&dest.sin_addr);
	src.sin_family=AF_INET;
	src.sin_port=htons(5000);
	inet_pton(AF_INET,"127.0.0.7",&src.sin_addr);
	
	int s_fd1=socket(AF_INET,SOCK_STREAM,0);
	
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
	 ret =connect(s_fd1,(struct sockaddr *)&dest,sizeof(dest));
	if(ret<0)
	{
		perror("connect");
		return -1;
	}
	char tempbuf[NAME_BUF_SIZE];
	printf("input 'end' over process\n ");
	bzero(&tempbuf,NAME_BUF_SIZE);
	
get:		gets(tempbuf);
	if(strcmp(tempbuf,"end")==0)
	{
		printf("process over\n");
		return 0;
	}
	send(s_fd1,tempbuf,20,0);
	recv(s_fd1,&name_buf,sizeof(Search),0);
	if(strcmp(name_buf.state,"yes")==0)
	{
		
		listen(s_fd,10);
		pthread_t pthread;
		int n=name_buf.data/FILE_SIZE+1;
		while(n--)
		{
			int c_fd=accept(s_fd,(struct sockaddr *)&temp,&len_temp);
			if(c_fd<0)
			{
				perror("accept");
				return -1;
			}
			
			pthread_create(&pthread,NULL,pthread_recv,(void *)&c_fd);
			pthread_detach(pthread);
			
		}
		
		goto get;





		
	/*	while(1)
		{
			bzero(buf,sizeof(Data));
			ret=recv(s_fd,buf,sizeof(Data),0);
			if(ret<=0)
			{
				return -1;
			}
			write(file,buf->data,BUF_SIZE);
		}       */
	}
}

