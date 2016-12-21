#ifndef _head_h
#define _head_h

#define BUF_SIZE 30
#define READ_SIZE 4096
typedef struct SEARCH
{
	char name[20];
	char state[10];
	double data;
	int count;
	struct sockaddr_in dest;
}Search;
typedef struct FILE_MESSAGE
{
	char name[20];
	int count ;
	char buf[READ_SIZE];
}File_message;
#define FILE_SIZE 204800000
#define BUF_SIZE 30

int search_file(Search * buf);
void *pthread_send(void * sfile);



#endif
