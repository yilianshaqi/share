//设置寄存器
#define   GPACON		(*(volatile unsigned int *)0x11400020)
#define 	ULCON			(*(volatile unsigned int *)0x13820000)
#define 	UCON			(*(volatile unsigned int *)0x13820004)
#define 	UBRDIV		(*(volatile unsigned int *)0x13820028)
#define 	UTXH			(*(volatile unsigned int *)0x13820020)

#define 	URXH			(*(volatile unsigned int *)0x13820024)
#define 	UFRACVAL	(*(volatile unsigned int *)0x1382002c)
#define 	URTSTAT		(*(volatile unsigned int *)0x13820010)

void inituart()
{
		GPACON = GPACON &~0xFF  | 0x2<<4   |0x2		;					//IO功能选择
		ULCON	 = ULCON	|0x3		|0x1<<2	   |0x0<<3   |0x0<<6		;	//数据格式配置	
		UBRDIV = UBRDIV | 53			;																//比特率设置
		UFRACVAL = UFRACVAL | 4		;
		UCON	=	 UCON	| 0x1<<2  | 0x1		;														//监控buffer方式设置
}
void senduart(char c)																//发送数据
{
	while( !(URTSTAT&2) );														//发送buffe非空是等待直到为空
	UTXH = c;
}
char receiveuart(void)																//接收数据
{
	char c;
	while( !(URTSTAT&1) );														//接受buffer为空时等待直到有数据时接收
	c = URXH;
	return c;
}


//led设置开始
void initled ()
{
	#define		GPF3CON (*(volatile unsigned int   *)0x114001e0)
	#define   GPF3DAT (*(volatile unsigned int   *)0x114001e4)
	//配置输出
		GPF3CON  = GPF3CON & 0xffff;
		GPF3CON  = GPF3CON | 0x110000;
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
void onled()
{
	GPF3DAT = GPF3DAT | 0x10 ;      //4bit位置1
	sleep(2);
	GPF3DAT = GPF3DAT & 0x2f ;      //4bit位置0
}
//led设置结束

int main()
{
	char c;
	inituart();
	initled();
	while(1)
	{
		c=receiveuart();
		onled();
		senduart(c);
	}
}
