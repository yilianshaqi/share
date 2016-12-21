#include"command.h"
int  main()
{

	int ret=-1;



	while(1)
	{	
		printf("please input command\n");
		bzero(buf,BUF_SIZE);
		success=1;

		
		
		if(success)
		{
			success=0;
			function();
			printf("function over \n");
			
		}
	
		
	}

}




int function()
{	
	//收到用户名
	
//	char temp_buf[TEMP_SIZE]="";
	
//	int ret=-1;
	char vbuf[SIZE]="";

	
	
	while(1)
	{
		printf("input command\n");
		bzero(vbuf,BUF_SIZE);
		strcpy(vbuf,"signout");

		if(strcmp(vbuf,"signout")==0)
		{	
			
			printf("siginout %s\n",vbuf);
			//  return 0;
			break;
		}

	}
	printf("down\n");
}

