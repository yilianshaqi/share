#include<stdio.h>
#include<netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>			
#include <sys/socket.h>
#include<string.h>

#define BUF_SIZE 4096
typedef struct DATA
{
	char func[10];
	char state[10];
	char data[BUF_SIZE];
}Data;
int main()
{
	Data *buf;
	bzero(buf,sizeof(Data));
	struct sockaddr_in dest;
	bzero(&dest,sizeof(dest));
	dest.sin_family=AF_INET;
	dest.sin_port=htons(6000);
	inet_pton(AF_INET,"127.0.0.10",&dest.sin_addr);

	int s_fd=socket(AF_INET,SOCK_STREAM,0);
	if(s_fd<0)
	{
		perror("socket");
		return -1;
	}
	int ret =connect(s_fd,(struct sockaddr *)&dest,sizeof(dest));
	if(ret<0)
	{
		perror("connect");
		return -1;
	}
	send(s_fd,"IMG_1002>jpg",10,0);
	recv(s_fd,buf,sizeof(Data),0);
	if(strcmp(buf->state,"yes")==0)
	{
		int file=open("../IMG",O_WRONLY|O_CREAT,0777);
		if(file<0)
		{
			perror("client open file");
			return -1;
		}
		while(1)
		{
			bzero(buf,sizeof(Data));
			ret=recv(s_fd,buf,sizeof(Data),0);
			if(ret<=0)
			{
				return -1;
			}
			write(file,buf->data,BUF_SIZE);
		}
	}
}
