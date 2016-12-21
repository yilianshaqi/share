.text
.global _start
_start:
   
	b reset      @reset
	nop			@undef
	nop			@svc
	nop 		@pretetch
	nop 		@data
	nop			@reserved
	nop         @irq
	nop 		@fiq
	

reset:	@��λ�����userģʽ������user��ջ������main����
	ldr r0, =0x40008000
	mcr p15, 0, r0, c12, c0, 0          @����������0x40008000Ϊ�ڴ�0x00000000��λ��
	
	ldr sp,=stackend
	bl led_init
	
	mrs r0,cpsr
	bic r0,#0x9F
	orr r0,#0x10
	msr cpsr,r0
	ldr sp,= userstackend
	
	b main
	
.data
	userstack:
		.space 128
	userstackend:
	
	stackstart:
		.space 128
	stackend:
.end
