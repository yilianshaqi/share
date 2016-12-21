//���üĴ���
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
		GPACON = GPACON &~0xFF  | 0x2<<4   |0x2		;					//IO����ѡ��
		ULCON	 = ULCON	|0x3		|0x1<<2	   |0x0<<3   |0x0<<6		;	//���ݸ�ʽ����	
		UBRDIV = UBRDIV | 53			;																//����������
		UFRACVAL = UFRACVAL | 4		;
		UCON	=	 UCON	| 0x1<<2  | 0x1		;														//���buffer��ʽ����
}
void senduart(char c)																//��������
{
	while( !(URTSTAT&2) );														//����buffe�ǿ��ǵȴ�ֱ��Ϊ��
	UTXH = c;
}
char receiveuart(void)																//��������
{
	char c;
	while( !(URTSTAT&1) );														//����bufferΪ��ʱ�ȴ�ֱ��������ʱ����
	c = URXH;
	return c;
}


//led���ÿ�ʼ
void initled ()
{
	#define		GPF3CON (*(volatile unsigned int   *)0x114001e0)
	#define   GPF3DAT (*(volatile unsigned int   *)0x114001e4)
	//�������
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
	GPF3DAT = GPF3DAT | 0x10 ;      //4bitλ��1
	sleep(2);
	GPF3DAT = GPF3DAT & 0x2f ;      //4bitλ��0
}
//led���ý���

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
