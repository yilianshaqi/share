#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
typedef struct MESSAGE
{	
	char txt;
	int type;
	int data;
	
}message;
int main()
{
	//get key
	key_t key;
	key=ftok("/home/farsight",10);
	if(key<0)
	{
		perror("ftok key");
		return -1;
	}
	//creat msg
	int msqid=-1;
	msqid = msgget(key,IPC_CREAT|0666);
	if(-1==msqid)
	{
		perror("msgget ");
		return -1;
	}
	//send message
	message Data;
	memset(&Data,0,sizeof(Data));
	int  rec=0;
	msgrcv(msqid,&Data,sizeof(Data),'p',0);
	printf("%d\n",Data.type);
	printf("%d\n",Data.data);
	printf("%c\n",Data.txt);
	//close msg
	msgctl(msqid,IPC_RMID,NULL);
	return -1;
}

