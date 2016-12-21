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
#include<pthread.h>


#define FILE_SIZE 204800000
#define READ_SIZE 2048
typedef struct DATA
{
	char name[30];
	char state[20];
	int count;
	double file_size;
	struct sockaddr_in dest;
	char data[READ_SIZE];
}Data;
#define NAME_SIZE 30



void * pthread_recv(void * fd)
{
	int c_fd=*(int *)fd;
	Data *buf;
	buf=(Data *)malloc(sizeof(Data));
	if(buf==NULL)
	{
		perror("malloc");
		return buf;
	}
	bzero(buf,sizeof(Data));
	recv(c_fd,buf,sizeof(Data),0);	
	int file=open(buf->name,O_WRONLY|O_CREAT,0777);

	if(file<0)
	{
		perror("client open file");
		pthread_exit(0);
	}
	lseek(file,buf->count*FILE_SIZE,SEEK_SET);
	while(1)
	{
		
		bzero(buf,sizeof(Data));
		int ret=recv(c_fd,buf->data,READ_SIZE,0);
		if(ret<=0)
		{	
			close(c_fd);
			pthread_exit(0);
		}
		write(file,buf->data,READ_SIZE);
	}
}	

int main()
{	
	Data *buf;
	buf=(Data *)malloc(sizeof(Data));
	if(buf==NULL)
	{
		perror("malloc");
		return -1;
	}
	bzero(buf,sizeof(Data));
	struct sockaddr_in dest,temp;
	bzero(&temp,sizeof(temp));
	int len_temp=sizeof(temp);
	bzero(&dest,sizeof(dest));
	dest.sin_family=AF_INET;
	dest.sin_port=htons(6000);
	inet_pton(AF_INET,"127.0.0.11",&dest.sin_addr);


	
	struct sockaddr_in src;
	bzero(&src,sizeof(src));
	src.sin_family=AF_INET;
	src.sin_port=htons(7000);
	inet_pton(AF_INET,"127.0.0.13",&src.sin_addr);

	
	int s_fd=socket(AF_INET,SOCK_STREAM,0);
	if(s_fd<0)
	{
		perror("socket");
		return -1;
	}
	connect(s_fd,(struct sockaddr *)&dest,sizeof(dest));
	char name[NAME_SIZE]="";
again:

	printf("input filename or input 'end' over process\n");
	gets(name);
	if(strcmp(name,"end")==0)
	{
		return 0;
	}
	strcpy(buf->name,name);
	send(s_fd,buf,sizeof(Data),0);
	bzero(&buf,sizeof(Data));
	recv(s_fd,buf,sizeof(Data),0);
	if(strcmp(buf->state,"yes")==0)
	{	
		buf->dest=src;
		int n=buf->file_size/FILE_SIZE+1;
		int c_fd=socket(AF_INET,SOCK_STREAM,0);
		bind(c_fd,(struct sockaddr *)&src,sizeof(struct sockaddr));
		listen(c_fd,10);
		send(s_fd,buf,sizeof(Data),0);
		pthread_t pthread;
		while(n--)
		{
			int fd=accept(c_fd,(struct sockaddr *)&temp,&len_temp);
			pthread_create(&pthread,NULL,pthread_recv,(void *)&fd);
			pthread_detach(pthread);
			printf("n=%d\n",n);
		}
		printf("goto \n");
		goto again;	
	}
}
