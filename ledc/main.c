
extern void  sleep(int );


int main()
{
	#define			GPF3CON (*(volatile int  *)0x114001e0)
	#define     GPF3DAT (*(volatile int *)0x114001e4)
	
	//配置输出
	GPF3CON  = GPF3CON & 0xffff;
	GPF3CON  = GPF3CON | 0x110000;
	//循环点亮
	while(1)
	{
		GPF3DAT = GPF3DAT | 0x10 ;      //4bit位置1
		GPF3DAT = GPF3DAT & 0x1f;				//5bit置0
		
		sleep(1);
		
		GPF3DAT = GPF3DAT & 0x2f ;      //4bit位置0
		GPF3DAT = GPF3DAT | 0x20 ;      //5bit位置1
		
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


