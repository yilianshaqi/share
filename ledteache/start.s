.text
.global _start
_start:

ldr r0, =0x11000C40
ldr r1, [r0]
bic r1, #0xF0000000
orr r1, #0x10000000
str r1, [r0]

loop:

ldr r0, =0x11000C44
ldr r1, [r0]
orr r1, #0x80
str r1, [r0]

bl delay

ldr r0, =0x11000C44
ldr r1, [r0]
bic r1, #0x80
str r1, [r0]

bl delay

b loop

delay:
ldr r0, = 0x10000000
mov  r1,#0
start:
	add r1,#1
	cmp r1,r0
	bne start
	mov pc, lr

.end
