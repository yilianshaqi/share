#include<stdio.h>
#include <sys/types.h>			
#include <sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <errno.h>

int main ()

{
	int sfd;
	struct sockaddr_in src,dest;
	int len_dest=sizeof(dest);
	int len_src=sizeof(src);
	bzero(&src,len_src);
	bzero(&dest,len_dest);
	src.sin_family=AF_INET;
	src.sin_port=htons(5001);
	inet_pton(AF_INET,"127.0.0.9",&src.sin_addr);
	
	
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
		perror("socket");
		return -1;
	}

	int  ret=-1;
	ret=bind(sfd,(struct sockaddr *)&src,len_src);
	if(ret<0)
	{
		perror("bind");
		return -1;
	}
	listen(sfd,10);

	int cfd=accept(sfd,(struct sockaddr *)&dest,&len_dest);
	printf("cfd=%d\n",cfd);
	if(cfd<0)
	{
		perror("accept");
		return -1;
	}
//	char buf[30]="";
	int ch=0;
//	recv(cfd,&buf,sizeof(buf),0);
	recv(cfd,&buf,sizeof(buf),0);
	printf("receive:%s\n",buf);



	close(cfd);
	close(sfd);
	return 0;
	}
