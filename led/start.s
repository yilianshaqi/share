.text 
.global _start
_start:
	@����GPIO
	ldr r0,=0x114001e0      @��Ӧ��ַ
	ldr r1,[r0]				@����GPF3���Ӧ��������
	bic r1,#0xff0000				@��GPF3_4��3_5�����������
	orr r1,#0x110000				@��GPF3_4��3_5�����������Ϊ���
	str r1,[r0]					@��������д��
loop:	
	@����GPF3_4
	ldr r0,=0x114001e4
	ldr r1,[r0]
	orr r1,#0x10       @GPF3_4����Ϊ1
	and r1,#0x1f		@GPF3_5����Ϊ0
	str r1,[r0]
	
	@��ʱ
	mov r4,#0	  
	again:

	add r4,#1
	ldr r5,=1000000
	cmp r4,r5
	nop
	nop
	nop
	nop
	bne again
	nop
	
	@����
	and r1,#0x2f			 @GPF3_4����Ϊ0
	orr r1,#0x20      		@GPF3_5����Ϊ1
	str r1,[r0]	
	
	@��ʱ
	mov r4,#0	  
	second:

	add r4,#1
	ldr r5,=1000000
	cmp r4,r5
	nop
	nop
	nop
	nop
	bne second
	nop
	
	b loop


.end	
	
	
	
	
	
