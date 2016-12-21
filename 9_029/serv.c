#include<stdio.h>
#include <sys/types.h>			
#include <sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <errno.h>
#include<pthread.h>
typedef struct ST
{
	char str1[5];
	char str2[4];
	int n;
}St;


void *receive(void *fd)
{
	St mes;
	bzero(&mes,sizeof(St));
	char buf[30]="";
	int cfd=*(int *)fd;
	int ret;
	while(1)
	{
		ret=recv(cfd,&mes,sizeof(St),0);
		if(ret==0)
		{
			close(cfd);
			printf("close ok\n");
			pthread_exit(0);
			
		}
	//	printf("receive:%s\n",buf);
	//	int ch=atoi(buf);
	//	printf("ch=%x\n",ch);
		printf("str1=%s\n",mes.str1);
		printf("str2=%s\n",mes.str2);
		printf("n=%d\n",mes.n);
	}
}







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
	inet_pton(AF_INET,"127.0.0.3",&src.sin_addr);
	
	
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
		perror("socket");
		return -1;
	}

	
int ret=-1;
	ret=bind(sfd,(struct sockaddr *)&src,len_src);
	if(ret<0)
	{
		perror("bind");
		return -1;
	}
	listen(sfd,10);
	while(1)
	{	
		bzero(&dest,len_dest);
		int cfd=accept(sfd,(struct sockaddr *)&dest,&len_dest);
		printf("cfd=%d\n",cfd);
		if(cfd<0)
		{
			perror("accept");
			return -1;
		}
		pthread_t pthread;
		if(pthread_create(&pthread,NULL,receive,&cfd)!=0)
		{
			perror("create pthread ");
			return -1;
		}
		pthread_detach(pthread);

	}
	close(sfd);
	return 0;
}


