
#define    GPD0CON        (*(volatile unsigned int *) 0x114000a0)
#define    TCFG0          (*(volatile unsigned int *) 0x139d0000)
#define    TCFG1          (*(volatile unsigned int *) 0x139d0004)
#define    TCNTB0					(*(volatile unsigned int *) 0x139d000c)	
#define 	 TCMPB0					(*(volatile unsigned int *) 0x139d0010)

#define    TCON           (*(volatile unsigned int *) 0x139d0008)
void pwm_init(void)
{
	GPD0CON = GPD0CON &~(0xf) | 2;       //GP管脚功能配置
	TCFG0 = TCFG0 &~(0xff)| 9 ;         //脉冲二级缩小第一次缩放
	TCFG1 = TCFG1 &~(0xf) | 4 ;          //脉冲二级缩小第二次缩放
	TCNTB0 =  TCNTB0	& 0 |  625   ;      //一个周期时钟脉冲数
	TCMPB0 = TCMPB0		& 0  | 312   ;      //占空比设置
	TCON = TCON  |(1<<3)  | (1<<1) | 1;   //自动赋值和赋值开启
//	TCON = TCON  |(1<<3) | 1;   //自动赋值和赋值开启
	TCON = TCON &~(1<<1);
}

int  main()
{
	pwm_init();
	while(1);
	
}
