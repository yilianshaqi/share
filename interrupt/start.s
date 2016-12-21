.text
.global _start
_start:                           @设置中断向量表
	b reset      @reset
	nop			@undef
	nop			@svc
	nop 		@pretetch
	nop 		@data
	nop			@reserved
	b irq_interupt  @irq
	nop 		@fiq
	
	
reset:	@复位后进入user模式，设置user的栈，进入main函数
	ldr r0, =0x40008000
	mcr p15, 0, r0, c12, c0, 0          @设置启动后0x40008000为内存0x00000000的位置
	
	
	
	
	
	mrs r0, cpsr
	bic r0, #0x1F
	orr r0, #0x12
	msr cpsr, r0
	ldr sp,=stackend
	
	mrs r0,cpsr
	bic r0,#0x9F
	orr r0,#0x10
	msr cpsr,r0
	ldr sp,= userstackend
	
	b main
	
irq_interupt:					@irq中断设置栈，跳到中断处理程序中去
	
	subs lr,lr,#4
	stmfd sp! ,{r0-r12,lr}
	bl interrupt	
	ldmfd sp! ,{r0-r12,pc}^
	
.data
	userstack:
		.space 128
	userstackend:
	
	stackstart:
		.space 128
	stackend:
.end
