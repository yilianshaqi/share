.text
.global _start
_start:

b reset   		@test
nop				@undefine
nop				@swi
nop				@prefect
nop 			@data
nop				@reserved
b irq_handle	@irq
nop				@fiq

reset:
@set interrupt vector to 0x40008000
ldr r0, =0x40008000
mcr p15, 0, r0, c12, c0, 0

@change svc to irq
mrs r0, cpsr
bic r0, #0x1F
orr r0, #0x12
msr cpsr, r0

@set irq stack
ldr sp, =irq_stack_end

@change irq to user, enable irq
mrs r0, cpsr
bic r0, #0x9F   @enable irq
orr r0, #0x10
msr cpsr, r0

@set user stack
ldr sp, =user_stack_end

b main

irq_handle:
sub lr, lr, #4
stmfd sp!, {r0-r12, lr}
b led_init
bl interrupt
ldmfd sp!, {r0-r12, pc}^

.data
	irq_stack:
		.space 128
	irq_stack_end:
	
	user_stack:
		.space 128
	user_stack_end:

.end
