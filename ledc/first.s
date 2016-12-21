.text
.global _start
_start:
	ldr sp,=buf
	bl main


.data
	buf:
	.space 1024
.end
