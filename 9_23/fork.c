#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	//check argument
/*	if(argc!=2)
	{
		printf("input error\n");
		return -1;
	}           */
	//creat process
	int repid;
	int num=3;
	repid=fork();
	if(-1==repid)
	{
		perror("fork");
		return -1;
	}
	if(0==repid)
	{
		// replace process
		sleep(10);
		printf("child=%d\n",getpid());
		printf("num=%d\n",num);
		num=9;
	/*	if(-1==(execl(argv[1],"NULL")))
		{
			perror("execl");
			return -1;               
		}          */
	}                  
	else
	{
		printf("parent process\n");
		int status;
		printf("num=%d\n",num);
		num=90;
//		int ret=wait(&status);
//		sleep(20);
//		int ret=waitpid(repid,&status,WNOHANG);
//		printf("exit ok ,parent=%d,%d,%d\n",getpid(),ret,WEXITSTATUS(status));
		printf("parent=%d\n",getpid());
		
	}
	return 0;
}
