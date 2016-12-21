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

int main()
{	
	//服务器ip端口配置
	struct sockaddr_in src,dest;
	bzero(&dest,sizeof(dest));
	int len_dest=sizeof(dest);
	bzero(&src,sizeof(src));
	src.sin_family=AF_INET;
	src.sin_port=htons(7000);
	inet_pton(AF_INET,"127.0.0.11",&src.sin_addr);
	//创建socket
	int s_fd=socket(AF_INET,SOCK_STREAM,0);
	if(s_fd<0)
	{
		perror("socket");
		return -1;
	}
	printf("s_fd=%d\n",s_fd);
	//bind IP和端口
	bind(s_fd,(struct sockaddr *)&src,sizeof(src));
	printf("bind ok\n");
	listen(s_fd,10);
	printf("listen ok\n");
	//accept client
	int c_fd=accept(s_fd,(struct sockaddr *)&dest,&len_dest);
	
	
	char buf[30]="";
	recv(c_fd,buf,30,0);
	printf("recv buf = %s\n",buf);
	//和客户端创建连接
	int new_fd=socket(AF_INET,SOCK_STREAM,0);
	sleep(1);
	int ret=connect(new_fd,(struct sockaddr *)&dest,sizeof(dest));
	if(ret<0)
	{
		perror("connect ");
		return -1;
	}
	printf("connect ok");
	send(new_fd,"receive your please",20,0);
	
	
	
	
}
