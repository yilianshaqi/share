/*************************************************************************
    > File Name: mysql.c
    > Author: huangyang
    > Mail: huangyangwork@sina.com 
    > Created Time: Sun 09 Oct 2016 05:04:08 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<mysql/mysql.h>
#include<string.h>

int main()
{
	MYSQL conn;
	MYSQL_RES *res;
	MYSQL_ROW sqlrow;
	MYSQL_FIELD *fd;
	char buf[100]="";

	mysql_init(&conn);
	if(mysql_real_connect(&conn,"localhost","root","123456","bracelet",0,NULL,0))
	{
		printf("connect ok\n");
	}
	else
	{
		printf("connect error\n");
	}
	int ret;
	
	ret=mysql_query(&conn,"select * from hy");
	printf("hy return ret= %d\n",ret);
	
	
	res=mysql_store_result(&conn);
	if(res == NULL)
	{
		perror("mysql_store_result");
		return -1;
	}
	/*
	ret=mysql_num_rows(res);
	printf("num row ret=%d\n",ret);
	while(sqlrow=mysql_fetch_row(res))
	{
		//strcpy(buf,fd->name);
		printf("result = %s\n",sqlrow[1]);
	}
	
	ret=mysql_query(&conn,"show tables");
	printf("hy return ret= %d\n",ret);

	
	res=mysql_store_result(&conn);
	if(res == NULL)
	{
		perror("mysql_store_result");
		return -1;
	}  
*/
	int i;
	while(sqlrow=mysql_fetch_row(res))
	{
		//strcpy(buf,fd->name);
		for(i=0;i<4;i++)
		{
			printf("result = %s\n",sqlrow[i]);

		}
	}
	


	ret=mysql_query(&conn,"select * from account where name='hhj'");		
	printf("hhj return ret= %d\n",ret);
	mysql_close(&conn);
}
