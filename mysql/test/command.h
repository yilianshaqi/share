#ifndef _common_h_
#define _common_h_
#include <sys/types.h>			
#include <sys/socket.h>
#include<netinet/in.h>
#include <pthread.h>
#include <unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include<stdio.h>
#include<mysql/mysql.h>

void * select_option(void * c_fd);


#endif


#ifndef _command_h_
#define _command_h_


int fd;
#define BUF_SIZE 256
#define TEMP_SIZE 256
#define SIZE 12



MYSQL conn;
MYSQL_RES 
*res_ptr;
MYSQL_ROW sqlrow;
MYSQL_FIELD *myfd;

int success=0;
char name[SIZE]="hy";
char buf[BUF_SIZE]="";

typedef struct ACCOUNT
{
	char name[SIZE];
	char passwd[SIZE];
}Account;
Account accbuf;

int signup();
int  signin();
int function();


#endif

