#include<stdio.h>
#include<string.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<netinet/in.h>

#define BUF_SIZE 1024

int main()
{
	struct sockaddr_in dest;
	bzero(&dest,sizeof(dest));
	dest.sin_family=AF_INET;
	dest.sin_port=htons(7777);
	inet_pton(AF_INET,"127.0.0.9",&dest.sin_addr);
	int ret=-1;
	char buf[BUF_SIZE]="";
	int s_fd=socket(AF_INET,SOCK_STREAM,0);	
	connect(s_fd,(struct sockaddr *)&dest,sizeof(dest));

	int file=open("hh.jpg",O_CREAT | O_WRONLY,0777);
	while(1)
	{
		ret=recv(s_fd,buf,BUF_SIZE,0);
		if(ret<=0)
		{
			perror("recv ");
			break;
		}
		printf("ret=%d\n",ret);
		write(file,buf,ret);
		bzero(buf,BUF_SIZE);
	}
	close(s_fd);
}
