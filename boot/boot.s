
.globl	_start
.text

_start:
.code16
		xorw	%ax, %ax
		movw	%ax, %ds
		movw	%ax, %ss
		movw	%ax, %fs
		jmp	start

start:
		movb	$'A', %al
		movb	$0x1E, %ah
		movl	$0xB8000, %ecx
		movl	%eax, (%ecx)
loop:		jmp	loop

. = _start + 510
.byte		0X55, 0xAA
