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
	inet_pton(AF_INET,"127.0.0.4",&dest.sin_addr);
	
	int cfd=socket(AF_INET,SOCK_STREAM,0);
	if(cfd<0)
	{
		perror("socket");
		return -1;
	}
	char buf[30]="0";
	
//		sleep(1);
		int ret=connect(cfd,(struct sockaddr *)&dest, len_dest);
		if(ret<0)
		{
			perror("connect");
			return -1;
		}
	
	while(1)
	{	
		bzero(buf,sizeof(buf));
		gets(buf);
		send(cfd,buf,6,0);
		printf("%s\n",buf);
	}
	close(cfd);
	return 0;
}

