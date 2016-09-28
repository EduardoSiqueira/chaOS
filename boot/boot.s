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


.section	.text
.globl	_start

_start:
.code16
		xorw	%ax,	%ax
		movw	%ax,	%ds
		movw	%ax,	%ss
		movw	%ax,	%fs
		jmp	start

start:

loop:
		#ler uma tecla, bloqueando execucao
		movb	$0x00,	%ah
		int	$0x16		#interrupt de teclado
		#a tecla lida eh salva no registrador %al em formato ASCII

		#printar um caracter(contido no registrador %al)
		movb	$0x0E,	%ah
		int	$0x10		#interrupt de video

		jmp	loop

. = _start + 510
.byte		0X55, 0xAA
