/*led register start*/
#define GPX2CON			*((volatile unsigned int *)0x11000C40)
#define GPX2DAT			*((volatile unsigned int *)0x11000C44)
/*led register end*/

/*uart register start*/
#define GPA1CON			*((volatile unsigned int *)0x11400020)
#define ULCON2			*((volatile unsigned int *)0x13820000)
#define UCON2			*((volatile unsigned int *)0x13820004)
#define UBRDIV2			*((volatile unsigned int *)0x13820028)
#define UFRACVAL2		*((volatile unsigned int *)0x1382002C)

#define UTXH2			*((volatile unsigned int *)0x13820020)
#define URXH2			*((volatile unsigned int *)0x13820024)
#define UTRSTAT2		*((volatile unsigned int *)0x13820010)
/*uart register end*/

/*key2 register start*/
#define GPX1CON			*((volatile unsigned int *)0x11000C20)
#define EXT_INT41CON	*((volatile unsigned int *)0x11000E04)
#define EXT_INT41_MASK	*((volatile unsigned int *)0x11000F04)
#define ICDISER1_CPU0	*((volatile unsigned int *)0x10490104)
#define ICDIPTR14_CPU0	*((volatile unsigned int *)0x10490838)

#define ICDIPR14_CPU0	*((volatile unsigned int *)0x10490438)
#define ICDDCR			*((volatile unsigned int *)0x10490000)
#define ICCPMR_CPU0		*((volatile unsigned int *)0x10480004)
#define ICCICR_CPU0		*((volatile unsigned int *)0x10480000)
#define ICCIAR_CPU0		*((volatile unsigned int *)0x1048000C)

#define ICDICPR1_CPU0	*((volatile unsigned int *)0x10490284)
#define EXT_INT41_PEND	*((volatile unsigned int *)0x11000F44)
#define ICCEOIR_CPU0	*((volatile unsigned int *)0x10480010)
/*key2 register end*/

/*led code start*/
void InitLed2()
{
	GPX2CON = GPX2CON &~ (0xF << 28) | (0x1 << 28);
}

void Led2Light()
{
	GPX2DAT = GPX2DAT | (0x1 << 7);
}

void Led2Off()
{
	GPX2DAT = GPX2DAT &~ (0x1 << 7);
}

void Delay()
{
	int i = 0;
	for (i = 0; i < 1000000; i++)
	{
		;
	}
}
/*led code end*/
/*uart code start*/
void InitUart()
{
	//set gpa1_0 and gpa1_1 uart transimt and receive function
	GPA1CON = GPA1CON &~ (0xFF) | 0x22;
	//set uart config
	/*		 mode		parity mode  	stop bit	data bits*/
	ULCON2 = 0 << 6 	| 0 << 3 		| 0 << 2 	| 3;
	//set transmit and receive mode
	/*						 transmit polling		receive polling*/
	UCON2 = UCON2 &~ (0xF) | (1 << 2) 				| 1;
	//set baud rate
	UBRDIV2 = 53;
	UFRACVAL2 = 4;
}

char ReceiveFromUart()
{
	while( !(UTRSTAT2 & 1) )
	{
		;
	}
	return URXH2;
}

void SendToUart(char c)
{
	while( !(UTRSTAT2 & (1 << 1)) )
	{
		;
	}
	UTXH2 = c;
}
/*uart code end*/

/*key2 code start*/
#define GPX1CON			*((volatile unsigned int *)0x11000C20)
#define EXT_INT41CON	*((volatile unsigned int *)0x11000E04)
#define EXT_INT41_MASK	*((volatile unsigned int *)0x11000F04)
#define ICDISER1_CPU0	*((volatile unsigned int *)0x10490104)
#define ICDIPTR14_CPU0	*((volatile unsigned int *)0x10490838)

#define ICDIPR14_CPU0	*((volatile unsigned int *)0x10490438)
#define ICDDCR			*((volatile unsigned int *)0x10490000)
#define ICCPMR_CPU0		*((volatile unsigned int *)0x10480004)
#define ICCICR_CPU0		*((volatile unsigned int *)0x10480000)
#define ICCIAR_CPU0		*((volatile unsigned int *)0x1048000C)

#define ICDICPR1_CPU0	*((volatile unsigned int *)0x10490284)
#define EXT_INT41_PEND	*((volatile unsigned int *)0x11000F44)
#define ICCEOIR_CPU0	*((volatile unsigned int *)0x10480010)
void InitKey2()
{
	GPX1CON = GPX1CON | (0xF << 4); //step 1
	EXT_INT41CON = EXT_INT41CON &~ ( 0x7 << 4) | (0x2 << 4); //step 2
	EXT_INT41_MASK = EXT_INT41_MASK &~ (0x1 << 1); //step 3
	ICDISER1_CPU0 = ICDISER1_CPU0 | (0x1 << (57	- 32)); //step 4
	ICDIPTR14_CPU0 = ICDIPTR14_CPU0 &~(0xFF << 8) | (0x1 << 8); //step 5
	ICDIPR14_CPU0 = ICDIPR14_CPU0 &~(0xFF << 8) | (12 << 8); //step 6
	ICDDCR = 1; //step7
	ICCPMR_CPU0 = 0xFF; //step 8
	ICCICR_CPU0 = 1; //step 9
}

void do_irq()
{
	int iNum = ICCIAR_CPU0 & 0x3FF;
	switch (iNum)
	{
		case 57:
		{
			SendToUart('h');
			SendToUart('e');
			ICDICPR1_CPU0 |= 1 << (57-32);
			EXT_INT41_PEND |= 1 << 1;
		}
		break;
	}
	ICCEOIR_CPU0 = ICCEOIR_CPU0 &~(0x3FF) | iNum;
}

/*key2 code end*/
int main()
{
	//init led2
	InitLed2();
	//init uart
	InitUart();
	char c = 0;
	//init key 2 interrupt
	InitKey2();
	while(1)
	{
		
	}
}