#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<string.h>


#define IPC_SIZE 20
#define DATA_SIZE 10
typedef  struct MESSAGE
{
	int num;
	char data[DATA_SIZE];
}message;

	  

int main()
{	
	//get key_t :key
	key_t key=ftok(".",1);
	if(key==-1)
	{
		perror("ftok get key");
		return -1;
	}
	//create IPC
	int shmid;
	shmid=shmget(key,IPC_SIZE,0666|IPC_CREAT);
	if(shmid==-1)
	{
		perror("create IPC");
		return -1;
	}
	//mapping address
	void *p=NULL;
	p=shmat(shmid,NULL,0);
	if(p==(void *)1)
	{
		perror("map address");
		return -1;
	}
	//access memory
	 
	printf("%s\n",(char *)p);
	while(1)
	{	
		if(*(char *)p!=0)
		{	
			printf("%s\n",(char *)p);
			memset(p,0,IPC_SIZE);
			sleep(2);
		}
	}
	//out map
	if(shmdt(p)==-1)
	{
		perror("out map");
		return -1;
	}
	
	//free IPC
//	sleep(30);
	return 0;
}

