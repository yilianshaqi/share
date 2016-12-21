#include<stdio.h>
#include<string.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<netinet/in.h>

#define BUF_SIZE 1024
#define MAX_LENGTH 64
typedef struct COMMAND_LINE
{

		char name[MAX_LENGTH];
			char argv1[MAX_LENGTH];
				char argv2[MAX_LENGTH];
}command_line;

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
	connect(s_fd,(struct sockaddr *)&dest,sizeof(dest));


	command_line  data;
	bzero(&data,sizeof(data));
	strcpy(data.name,"CD");
	strcpy(data.argv1,"/mnt/hgfs/share");
	send(s_fd,&data,sizeof(data),0);

	bzero(&data,sizeof(data));
	strcpy(data.name,"LS");

	send(s_fd,&data,sizeof(data),0);

	while(1)
	{
		printf("input a string\n");
		gets(buf);
		send(s_fd,buf,BUF_SIZE,0);
		bzero(buf,BUF_SIZE);
		recv(s_fd,buf,BUF_SIZE,0);
		printf("recv=%s\n",buf);
		bzero(buf,BUF_SIZE);

	}
	close(s_fd);
}
