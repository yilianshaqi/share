

#define   WTCON       (*(volatile unsigned int *) 0x10060000)
#define   WTCNT				(*(volatile unsigned int *) 0x10060008)

void watchdog_init(void)
{
		WTCON  = WTCON &~(0xff<<8) | (249<<8)  | (1<<5) | (3<<3) | 1  ;   //����watchdog���ÿ���ʹ��
		WTCNT  = WTCNT &~(0xffff)  | (15625)  ;   //����watchdog����ʱ��
	
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

void led_init(void)
{
	#define			GPF3CON (*(volatile int  *)0x114001e0)
	#define     GPF3DAT (*(volatile int  *)0x114001e4)
	GPF3CON  = GPF3CON & 0xffff;
	GPF3CON  = GPF3CON | 0x110000;
	GPF3DAT = GPF3DAT | 0x10 ;      //4bitλ��1
	sleep(2);
	GPF3DAT = GPF3DAT & 0x2f ;  //4bitλ��0
	sleep(2);	
}


int main()
{
	//��ʼ��watdog
	watchdog_init();
	
	
	
	//��ѭ���ȴ�reset����
	while(1)
	{
		
		sleep(1);
	}
}