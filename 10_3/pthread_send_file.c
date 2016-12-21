#include<string.h>
#include <sys/types.h>
#include <unistd.h>

void * pthread_send_file(void *count)
{
	Pthread_data pfile;
	bzero(&pfile,sizeof(Pthread_data));
	Data *buf;
	bzero(buf,sizeof(Data));
	pfile=*(Pthread_data *)count;
	int file=open("pfile.data",O_RDONLY);
	if(file<0)
	{
		perror("open file");
		return -1;
	}
	lseek(file,pfile.count*(FILE_SIZE),SEEK_SET);
	int i=0;
	while(i<(FILE_SIZE/BUF_SIZE))
	{	
		bzero(buf,sizeof(Data));
		int ret=read(file,buf->data,BUF_SIZE);
		if(ret<=0)
		{
			return -1;	
		}
		select_message(NULL,buf->data,(port+pfile.count));
	}
	return 0;
}
