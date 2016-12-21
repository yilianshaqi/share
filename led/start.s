.text 
.global _start
_start:
	@配置GPIO
	ldr r0,=0x114001e0      @对应地址
	ldr r1,[r0]				@读出GPF3组对应配置数据
	bic r1,#0xff0000				@对GPF3_4和3_5针脚配置清零
	orr r1,#0x110000				@对GPF3_4和3_5针脚配置设置为输出
	str r1,[r0]					@配置数据写入
loop:	
	@点亮GPF3_4
	ldr r0,=0x114001e4
	ldr r1,[r0]
	orr r1,#0x10       @GPF3_4设置为1
	and r1,#0x1f		@GPF3_5设置为0
	str r1,[r0]
	
	@延时
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
	
	@换灯
	and r1,#0x2f			 @GPF3_4设置为0
	orr r1,#0x20      		@GPF3_5设置为1
	str r1,[r0]	
	
	@延时
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
	
	
	
	
	
