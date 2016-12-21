#ifndef _head_h
#define _head_h

#define FILE_SIZE 204800000
#define READ_SIZE 2048
typedef struct DATA
{
	char name[30];
	char state[20];
	int count;
	double file_size;
	struct sockaddr_in dest;
	char data[READ_SIZE];
}Data;
int search_file(Data * buf);
void *pthread_send(void *buf);


#endif

