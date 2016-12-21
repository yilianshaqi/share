#define 	GPX1CON    			(*(volatile unsigned int *) 0x11000C20)
#define 	EXT_INT41CON    (*(volatile unsigned int *) 0x11000E04)
#define 	EXT_INT41_MASK  (*(volatile unsigned int *) 0x11000F04)
#define 	ICDISER_CPU			(*(volatile unsigned int *) 0x10490104)
#define 	ICDIPR_CPU			(*(volatile unsigned int *) 0x10490438)

#define 	ICDIPTR_CPU			(*(volatile unsigned int *) 0x10490838)
#define 	ICDDCR					(*(volatile unsigned int *) 0x10490000)
#define		ICCPMR_CPU0			(*(volatile unsigned int *) 0x10480004)
#define   ICCICR_CPU0			(*(volatile unsigned int *) 0x10480000)
#define 	ICCIAR_CPU0			(*(volatile unsigned int *) 0x1048000C)


void irq_init(void)
{
	GPX1CON = GPX1CON | (0XF << 4) ;    												//io口设置为中断信号管脚
	EXT_INT41CON = EXT_INT41CON &~(7<<4)  | (2<<4)	;						//设置信号触发方式
	EXT_INT41_MASK = EXT_INT41_MASK &~(1<<1)  ;   							//硬件信号是否捕捉的掩码（硬件使能开启）
	ICDISER_CPU = ICDISER_CPU | (1<<(57-32))   ; 								//GIC 使能开启
	ICDIPR_CPU = ICDIPR_CPU &~(0xff<<8)| (7<<8) ;          		  // 中断优先级设置
	ICDIPTR_CPU = ICDIPTR_CPU &~(0xff<<8)  | (1<<8)  ;           //设置哪个处理器处理该信号可设多个处理器
	ICDDCR = 1  ;                                               //GIC使能开启（所有的处理）
	ICCPMR_CPU0 =  0xff;                                         //处理器处理信号优先级设定（针对每一个处理的设定）
	ICCICR_CPU0 = 1 ;                                            //处理器使能开启（针对每一个处理器的设定）
	
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
	GPF3DAT = GPF3DAT | 0x10 ;      //4bit位置1
	sleep(2);
	GPF3DAT = GPF3DAT & 0x2f ;  //4bit位置0
	sleep(2);	
}


void interrupt(void)
{
		int num = (ICCIAR_CPU0  & 0x3FF );   	//获取中断ID
		led_init();
		switch (num)
		{
				case 57:
				led_init();
				break;
		}
}






int main()
{
		irq_init();
	while(1)
	{
	//	led_init();
		;
	}
}
