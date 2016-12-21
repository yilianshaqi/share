#include"common.h"
#include"command.h"


void * select_option(void * c_fd)
{
	fd=*(int *)c_fd;
	int ret=-1;

	pthread_detach(pthread_self());
	mysql_init(&conn);
	if( mysql_real_connect(&conn,"localhost","root","123456","bracelet",0,NULL,0) )
	{
//		send(fd,"ok",2,0);
		printf("connect ok\n");
	}
	while(1)
	{	
		printf("please input command\n");
		bzero(buf,BUF_SIZE);
		ret=recv(fd,buf,BUF_SIZE,0);
		if(ret<0)
		{
			perror("recv command");
			send(fd,"no",2,0);
			continue;
		}
		if(strcmp(buf,"signup")==0)
		{
			
			signup();
		}
		else
		 if(strcmp(buf,"signin")==0)
		{
			signin();
		}
		else
		if(strcmp(buf,"bye")==0)
		{
			break;
		}
		
		if(success)
		{
			success=0;
			function();
			printf("function over \n");
			
		}
		if(ret==0)
		{
			break;
		}
		
	}
	close(fd);
	pthread_exit(0);
}



int signup()
{	
	int ret=-1;
	char temp_buf[TEMP_SIZE]="";
	int i;
	send(fd,"ok",2,0);
	bzero(&accbuf,sizeof(Account));
	recv(fd,&accbuf,sizeof(Account),0);//ע��buf���ݸ�ʽ  �����û���������  hy,111222
	
	sprintf(temp_buf,"select * from account where name ='%s'",accbuf.name);
	ret = mysql_query(&conn,temp_buf); //�����Ƿ�����ͬ��name
	if(ret != 0)
	{
		perror("mysql_query");
		send(fd,"no",2,0);
		printf("%d signup no\n",__LINE__);
		return -1;       //����ע��ʧ����Ϣ
	}
	res_ptr = mysql_store_result(&conn);
	if(res_ptr ==NULL )
	{
		perror("mysql_store_result");
		send(fd,"no",2,0);
		printf("%d signup no\n",__LINE__);
		return -1;          //����ע��ʧ����Ϣ
	}
	ret = mysql_num_rows(res_ptr);
	if(ret != 0)
	{
		send(fd,"no",2,0);  //����ע��ʧ����Ϣ
		printf("%d signup no\n",__LINE__);
		return -1;
	}
	
	bzero(temp_buf,sizeof(temp_buf));
	sprintf(temp_buf,"insert into account values('%s',%s)",accbuf.name,accbuf.passwd);
	ret=mysql_query(&conn,temp_buf); // �����û���������ע��
	if(ret==0)
	{
		send(fd,"ok",3,0);
		printf("%d signup OK\n",__LINE__);
	}
	else
	{
		send(fd,"no",2,0);
		printf("%d signup no\n",__LINE__);
	}
	mysql_free_result(res_ptr);
	return 0;
}




int  signin()
{
	int ret=-1;
	
	
	char getpasswd[10]="";
	char temp_buf[TEMP_SIZE]="";
	send(fd,"ok",2,0);
	bzero(&accbuf,sizeof(Account));
	recv(fd,&accbuf,sizeof(Account),0);  //�����û��������� hy,111222
	printf("%d get account \n",__LINE__);
	sprintf(temp_buf,"select * from account where name='%s'",accbuf.name);
	
	ret = mysql_query(&conn,temp_buf);//�����û���
	if(ret != 0)
	{
		perror("mysql_query");
		send(fd,"no",2,0);
		printf("%d signin no\n",__LINE__);
		return -1;       //���ص�¼ʧ����Ϣ
	}
	res_ptr = mysql_store_result(&conn);
	
	if(res_ptr == NULL )
	{
		perror("mysql_store_result");
		send(fd,"no",2,0);
		printf("%d signin no\n",__LINE__);
		return -1;          //���ص�¼ʧ����Ϣ
	}
	sqlrow = mysql_fetch_row(res_ptr); // �õ�����
	
	if(sqlrow==NULL)
	{
		send(fd,"no",2,0);  //���ص�¼ʧ����Ϣ
		printf("%d signin no\n",__LINE__);
		return -1;
	}
	else
	{
		strcpy(getpasswd,sqlrow[1]);
		printf("passwd=%s\n",sqlrow[1]);
	}
	if(strcmp(getpasswd,accbuf.passwd)==0)   // �Ƚϵ�¼�����Ƿ���ȷ
	{
		success=1;
		bzero(name,SIZE);
		strcpy(name,accbuf.name);
		send(fd,"ok",2,0); //���ص�¼�ɹ���Ϣ
		printf("%d signin ok\n",__LINE__);
		
	}
	else
	{
		send(fd,"no",2,0);  //���ص�¼ʧ����Ϣ
		printf("passwd=%s\n",sqlrow[1]);
	}
	mysql_free_result(res_ptr);
	return 0;
	
}
int insert()
{
	bzero(buf,BUF_SIZE);
	recv(fd,buf,BUF_SIZE,0);
	char temp_buf[TEMP_SIZE]="";
	sprintf(temp_buf,"insert into %s values(%s)",name,buf);
	int ret=-1;
	ret = mysql_query(&conn,temp_buf);
	printf(" %d get data\n",__LINE__);
	if(ret != 0)
	{
		perror("mysql_query");
		send(fd,"no",2,0);
		printf(" %d insert no \n",__LINE__);
		return -1;       //����ʧ����Ϣ
	}
	else
	{
		send(fd,"ok",2,0);
		printf(" %d insert ok \n",__LINE__);
	}
	return 0;
}

int delet ()
{
	bzero(buf,BUF_SIZE);
	recv(fd,buf,BUF_SIZE,0);
	char temp_buf[TEMP_SIZE]="";
	sprintf(temp_buf,"delete from %s where time =%s",name,buf);
	int ret=-1;
	ret = mysql_query(&conn,temp_buf);
	if(ret != 0)
	{
		perror("mysql_query");
		send(fd,"no",2,0);
		printf(" %d delet no \n",__LINE__);
		return -1;       //����ʧ����Ϣ
	}
	else
	{
		send(fd,"ok",2,0);
		printf(" %d delet ok \n",__LINE__);
	}
	return 0;
}

int show()
{
	
	char temp_buf[TEMP_SIZE]="";
	sprintf(temp_buf,"select * from %s ",name);
	int ret=-1;
	int i;
	ret = mysql_query(&conn,temp_buf);
	if(ret != 0)
	{
		perror("mysql_query");
		send(fd,"no",2,0);
		printf(" %d show no\n",__LINE__);
		return -1;       //����ʧ����Ϣ
	}
	res_ptr = mysql_store_result(&conn);
	if(res_ptr == NULL )
	{
		perror("mysql_store_result");
		send(fd,"no",2,0);
		printf(" %d show no\n",__LINE__);
		return -1;          //����ʧ����Ϣ
	}
	
	while(sqlrow = mysql_fetch_row(res_ptr))
	{	
		for(i=0;i<4;i++)
		{
			send(fd,sqlrow[i],16,0);
		}
	}
	send(fd,"fin",3,0);
	printf(" %d show ok\n",__LINE__);
	mysql_free_result(res_ptr);
	return 0;
}




int function()
{	
	//�յ��û���
	
	char temp_buf[TEMP_SIZE]="";
	
	int ret=-1;
	char vbuf[SIZE]="";
	
	//�������Ƿ����
	ret=mysql_query(&conn,"show tables");
	if(ret != 0)
	{
		perror("mysql_query");
		send(fd,"no",2,0);
		return -1;       //����ʧ����Ϣ
	}
	res_ptr = mysql_store_result(&conn);
	if(res_ptr ==NULL )
	{
		perror("mysql_store_result");
		send(fd,"no",2,0);
		return -1;          //����ʧ����Ϣ
	}
	
	while(sqlrow = mysql_fetch_row(res_ptr))
	{
		if(strcmp(name,sqlrow[0])==0)  //����
		{
			break;
		}
	}
	if(sqlrow == NULL )   //������:����
	{
		sprintf(temp_buf,"create table %s (time varchar(10) not null primary key,step varchar(16),km varchar(8),sleep varchar(8))",name);
		ret = mysql_query(&conn,temp_buf);
		if(ret != 0)
		{
			perror("mysql_query");
			send(fd,"no",2,0);
			return -1;       //����ʧ����Ϣ
		}
	}
	mysql_free_result(res_ptr);
	
	
	while(1)
	{
		printf("input command\n");
		bzero(vbuf,BUF_SIZE);
		ret = recv(fd,vbuf,BUF_SIZE,0);
		if(strcmp(vbuf,"insert")==0)
		{
			insert();  //�������ݺ���
		}
		if(strcmp(vbuf,"delete")==0)
		{
			delet();  //ɾ�����ݺ��� 
		}
		if(strcmp(vbuf,"show")==0)
		{
			show();  // ��ʾ���ݺ���
		}       
		
		if(strcmp(vbuf,"signout")==0)
		{	
			
			printf("siginout %s\n",vbuf);
			//  return 0;
			break;
		}
		if(ret ==0)
		{
			break;
		}   
	}
	printf("down\n");
}

