
extern void  sleep(int );


int main()
{
	#define			GPF3CON (*(volatile int  *)0x114001e0)
	#define     GPF3DAT (*(volatile int *)0x114001e4)
	
	//�������
	GPF3CON  = GPF3CON & 0xffff;
	GPF3CON  = GPF3CON | 0x110000;
	//ѭ������
	while(1)
	{
		GPF3DAT = GPF3DAT | 0x10 ;      //4bitλ��1
		GPF3DAT = GPF3DAT & 0x1f;				//5bit��0
		
		sleep(1);
		
		GPF3DAT = GPF3DAT & 0x2f ;      //4bitλ��0
		GPF3DAT = GPF3DAT | 0x20 ;      //5bitλ��1
		
		sleep(1) ;
	}
}

void sleep(int num)
{
	num=num*1000000;
	int i=0;
	do
	{
		i++;
	}while(i!=num);
}


