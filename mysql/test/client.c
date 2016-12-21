#include<stdio.h>
#include<string.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<netinet/in.h>

#define BUF_SIZE 256
typedef struct ACCOUNT
{

	char name[12];
	char passwd[12];
}Account;
Account data;
int main()
{
	struct sockaddr_in dest;
	bzero(&dest,sizeof(dest));
	dest.sin_family=AF_INET;
	dest.sin_port=htons(8000);
	inet_pton(AF_INET,"127.0.0.9",&dest.sin_addr);
	int ret=-1;
	char buf[BUF_SIZE]="";
	int s_fd=socket(AF_INET,SOCK_STREAM,0);	
go:	
	ret=connect(s_fd,(struct sockaddr *)&dest,sizeof(dest));
	if(ret==0)
	{
		printf("connect ok\n");
	}
	else
	{
		perror("connect");
		goto go ;
	}
	while(1)
	{
		printf("input r to recv or input s to send or input t to struct\n");
		gets(buf);
		if(strcmp(buf,"r")==0)
		{
			bzero(buf,BUF_SIZE);
			gets(buf);
			recv(s_fd,buf,BUF_SIZE,0);
			printf("recv=%s\n",buf);
			bzero(buf,BUF_SIZE);

		}
		if(strcmp(buf,"s")==0)
		{
			bzero(buf,BUF_SIZE);
			gets(buf);
			printf("sendbuf=%s\n",buf);
			send(s_fd,buf,BUF_SIZE,0);
			bzero(buf,BUF_SIZE);

		}
		if(strcmp(buf,"t")==0)
		{
			bzero(&data,sizeof(data));
			
			gets(data.name);
			gets(data.passwd);
			printf("data_name=%s,data_passwd=%s\n",data.name,data.passwd);
			send(s_fd,&data,sizeof(data),0);
			bzero(buf,BUF_SIZE);
		}

	}
	close(s_fd);
}
