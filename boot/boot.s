
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
		nop
loop:		jmp	loop

. = _start + 510
.byte		0X55, 0xAA
