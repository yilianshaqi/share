.text
.global _start
_start:                           @�����ж�������
	b reset      @reset
	nop			@undef
	nop			@svc
	nop 		@pretetch
	nop 		@data
	nop			@reserved
	b irq_interupt  @irq
	nop 		@fiq
	
	
reset:	@��λ�����userģʽ������user��ջ������main����
	ldr r0, =0x40008000
	mcr p15, 0, r0, c12, c0, 0          @����������0x40008000Ϊ�ڴ�0x00000000��λ��
	
	
	
	
	
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
	
irq_interupt:					@irq�ж�����ջ�������жϴ��������ȥ
	
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
