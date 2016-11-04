# Copyright © 2016
# 
# 	Ali de França Husseinat			n°USP: 9292966 
# 	Eduardo de Sousa Siqueira		n°USP: 9278299
# 	Lucas Silva Marcondes			n°USP: 9293612
# 	Ricardo Fernandes França do Vale	n°USP: 9293477 
# 
# This file is part of ChaOS.
# 
# ChaOS is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# ChaOS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# 
# You should have received a copy of the GNU General Public License
# along with ChaOS.  If not, see <http://www.gnu.org/licenses/>.

.set FLAGS,	0 | 1            # flag de multiboot
.set MAGIC,	0x1BADB002       # numero que permite ao bootloader encontrar o header
.set CHECKSUM,	-(MAGIC + FLAGS) # checksum of above, to prove we are multiboot
.set STACKSIZE,	0x4000           # tamanho da pilha

.section	.text
.globl	_start

_start:
	jmp	multiboot
	.align 4
multiboot_header: #assinatura de multiboot
	.long MAGIC
	.long FLAGS
	.long CHECKSUM

multiboot: #secao do codigo do multiboot em si
	movl    $(stack + STACKSIZE), %esp
	call	kernel_main

loop:   hlt
        jmp     loop

        .comm   stack, STACKSIZE

