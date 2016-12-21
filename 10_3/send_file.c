#include<stdio.h>
#define FILE_SIZE 204800000
typedef struct PTHREAD_DATA
{
	int count;
	char file[20];
}Pthread_data;

int send_file(Data *buf)
{
	int n=buf->data/FILE_SIZE;
	int i;
	Pthread_data pfile;
	bzero(&pfile,sizeof(Pthread_data));
	strcpy(pfile.file,buf->data);
	for(i=0;i<=n;i++)
	{
		pfile.count=i;
		
	}
}
