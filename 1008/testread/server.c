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
	struct sockaddr_in src,dest;
	bzero(&dest,sizeof(dest));
	int len_dest=sizeof(dest);
	bzero(&src,sizeof(src));
	char buf[BUF_SIZE]="";
	int ret=-1;	

	
	src.sin_family=AF_INET;
	src.sin_port=htons(7777);
	inet_pton(AF_INET,"127.0.0.9",&src.sin_addr);

	int s_fd=socket(AF_INET,SOCK_STREAM,0);
	bind(s_fd,(struct sockaddr *)&src,sizeof(src));

	listen(s_fd,10);
	int c_fd=accept(s_fd,(struct sockaddr *)&dest,&len_dest);

	int file=open("hy.jpg",O_RDONLY);
	while(ret=read(file,buf,BUF_SIZE))
	{
		if(ret<=0)
		{
			printf("file over\n");
			break ;
		}
		send(c_fd,buf,ret,0);
		
	}
	close(c_fd);
	close(s_fd);
	return 0;
}
