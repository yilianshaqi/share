#include<stdio.h>
#include <sys/types.h>			
#include <sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <errno.h>
int main()
{
	 struct ST
	{
		char str1[5];
		char str2[4];
		int n;
	}St={"worl","yyt",18};
	




//	bzero(&message,sizeof(St));
	struct sockaddr_in dest;
	int len_dest=sizeof(dest);
	bzero(&dest,len_dest);

	dest.sin_family=AF_INET;
	dest.sin_port=htons(5001);
	inet_pton(AF_INET,"127.0.0.3",&dest.sin_addr);
	
	int cfd=socket(AF_INET,SOCK_STREAM,0);
	if(cfd<0)
	{
		perror("socket");
		return -1;
	}
	int ret=connect(cfd,(struct sockaddr *)&dest, len_dest);
	if(ret<0)
	{
		perror("connect");
		return -1;
	}
//	char buf[20]="";
//	int math=1234567;
//	sprintf(buf,"%x",math);
	send(cfd,&St,sizeof(struct ST),0);
	close(cfd);
	return 0;
}
