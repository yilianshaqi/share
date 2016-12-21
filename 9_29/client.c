#include<stdio.h>
#include <sys/types.h>			
#include <sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <errno.h>
int main()
{
	struct sockaddr_in dest;
	int len_dest=sizeof(dest);
	bzero(&dest,len_dest);

	dest.sin_family=AF_INET;
	dest.sin_port=htons(5001);
	inet_pton(AF_INET,"127.0.0.9",&dest.sin_addr);
	
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
	send(cfd,"hello!",6,0);
	close(cfd);
	return 0;
}
