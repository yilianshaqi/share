#include<stdio.h>
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
	Data.type=9;
	Data.data=10;
	Data.txt='p';
	msgsnd(msqid,&Data,sizeof(Data),0);
	message ss;
	ss.type=20;
	ss.data=99;
	ss.txt='o';
	msgsnd(msqid,&ss,sizeof(Data),0);
	//close msg
//	msgctl(msqid,IPC_RMID,NULL);
	return -1;
}
