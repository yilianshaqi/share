
#define    GPD0CON        (*(volatile unsigned int *) 0x114000a0)
#define    TCFG0          (*(volatile unsigned int *) 0x139d0000)
#define    TCFG1          (*(volatile unsigned int *) 0x139d0004)
#define    TCNTB0					(*(volatile unsigned int *) 0x139d000c)	
#define 	 TCMPB0					(*(volatile unsigned int *) 0x139d0010)

#define    TCON           (*(volatile unsigned int *) 0x139d0008)
void pwm_init(void)
{
	GPD0CON = GPD0CON &~(0xf) | 2;       //GP�ܽŹ�������
	TCFG0 = TCFG0 &~(0xff)| 9 ;         //���������С��һ������
	TCFG1 = TCFG1 &~(0xf) | 4 ;          //���������С�ڶ�������
	TCNTB0 =  TCNTB0	& 0 |  625   ;      //һ������ʱ��������
	TCMPB0 = TCMPB0		& 0  | 312   ;      //ռ�ձ�����
	TCON = TCON  |(1<<3)  | (1<<1) | 1;   //�Զ���ֵ�͸�ֵ����
//	TCON = TCON  |(1<<3) | 1;   //�Զ���ֵ�͸�ֵ����
	TCON = TCON &~(1<<1);
}

int  main()
{
	pwm_init();
	while(1);
	
}
