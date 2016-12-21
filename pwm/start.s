.text
.global _start
_start:
	
	ldr r0,=stackend
	bl main
.data
	stackstart:
	.space 128
	stackend:
.end
