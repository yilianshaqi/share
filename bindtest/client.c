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
int main()
{
	//创建client的IP和端口配置
	struct sockaddr_in src ;
	bzero(&src ,sizeof(src));
	src.sin_family=AF_INET;
	src.sin_port=htons(8000);
	inet_pton(AF_INET,"127.0.0.20",&src.sin_addr);
	//创建要连接的service IP和端口配置
	struct sockaddr_in dest ;
	bzero(&dest ,sizeof(dest));
	dest.sin_family=AF_INET;
	dest.sin_port=htons(7000);
	inet_pton(AF_INET,"127.0.0.11",&dest.sin_addr);
	//创建接受IP空buf
	struct sockaddr_in temp ;
	bzero(&temp ,sizeof(temp));
	int len_temp=sizeof(temp);
	//创建socket
	int s_fd=socket(AF_INET,SOCK_STREAM,0);

	
	//bind 客户端自己的IP
	bind(s_fd,(struct sockaddr *)&src,sizeof(src));
	//connect 服务器
	int ret = connect(s_fd,(struct sockaddr *)&dest,sizeof(dest));
	if(ret<0)
	{
		perror("connect ");
		return -1;
	}
	printf("connect ok\n");
	send(s_fd,"first please",12,0);

	close(s_fd);
	int new_fd=socket(AF_INET,SOCK_STREAM,0);
	bind(new_fd,(struct sockaddr *)&src,sizeof(src));
	listen(new_fd,10);
	int c_fd=accept(new_fd,(struct sockaddr *)&temp,&len_temp);
	if(c_fd<0)
	{
		perror("accept");
		return -1;
	}
	printf("accept ok \n");
	char buf[50]="";
	recv(c_fd,buf,50,0);
	printf("recv buf =%s\n",buf);
	

	
}



