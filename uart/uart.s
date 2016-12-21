.text
.global _start
_start:
	
	ldr sp,=stack
	b main

.data 
	stack:
	.space 255
.end
