#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define BUF_SIZE 10
int main()
{	
	//creat pipe
	int fp[2];
	pipe(fp);
	char buf[BUF_SIZE]={0};
	int pid=0;
	pid=fork();
	if(pid<0)
	{
		perror("creat fork");
		return -1;
	}
	if(pid==0)
	{	
		strcpy(buf,"hello");
		write(fp[1],buf,5);
		memset(buf,0,BUF_SIZE);
		sleep(3);
		read(fp[0],buf,BUF_SIZE);
		printf("%s\n",buf);
	}
	if(pid>0)
	{	
		sleep(1);
		read(fp[0],buf,3);
		printf("%s\n",buf);
		memset(buf,0,BUF_SIZE);
		strcpy(buf,"world");
		write(fp[1],buf,5);
		sleep(5);
		FILE *file=fdopen(fp[0],"r+");
		printf("%p",file->_IO_buf_base);

	}
	return ;
}

