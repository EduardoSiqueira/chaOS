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
	    char_switch:
	
            #quando enter, passa para a proxima linha
		case_enter:
		        movb	$0x0D,	%bl	#carriage return - '\r'
		        cmp	%bl,	%al	#detectando o enter
		        jne	case_clear_screen

		        #quando o enter eh pressionado, imprime um newline e logo apos um carriage return
			call print_newline

		        jmp	default

            #quando for apertada a tecla 1, a tela sera limpada
		case_clear_screen:
			movb    $0x31,	%bl #valor de 1 na tabela ascii em hexadecimal eh colocado em bl 
			cmp     %bl,	%al
			jne 	case_memory_size
		
			#quando o 1 eh pressionado, a tela e limpada
			call	clear_screen

			jmp	loop

		case_memory_size:
			movb	$0x35,	%bl
			cmp	%bl,	%al
			jne	default

			call	print_newline
			call	memory_size
			call	print_newline

			jmp	loop
		default:
		        #printar um caracter(contido no registrador %al)
		        movb	$0x0E,	%ah
		        int	$0x10		#interrupt de video

		        jmp	loop
print_newline:
		pusha	#protegendo os valores fora da funcao

		movb	$0x0A,	%al	#newline - '\n'
		movb	$0x0E,	%ah
		int	$0x10

		movb	$0x0D,	%al
		int	$0x10

		popa	#restaurando os valores
		ret

clear_screen:
		pusha

		movb    $0x06, %ah #valor de ah para limpar a tela, rolando-a para cima
		movb    $0x00, %al #valor setado para indicar que toda a pagina deve ser limpada
		movb    $0x07, %bh #atributo usado na linha limpada
		movw    $0x0000, %cx #posicao de inicio para limpar a tela
		movw    $0x184F, %dx #posicao de fim para limpar a tela
		int     $0x10 #interrupt de video    

		#por fim, eh necessario setar o cursor na posicao inicial da tela
		movb    $0x02, %ah #valor de ah para setar posicao de cursor
		movb    $0x00, %bh #valor da pagina default
		#setando posicao no topo a esquerda
		movb    $0x00, %dh
		movb    $0x00, %dl
		int     $0x10 #interrupt de video    

		popa
		ret

memory_size:
		pusha

		int	$0x12
		#retorna o tamanho da memoria no registrador %ax
		#que eh dividido em: %ah - bits 8-15 | %al - bits 0-7

		movb	%ah,	%bh	#movendo primeiro byte
		movb	%al,	%bl	#movendo segundo byte

		movb	$4,	%dl	#contador de iteracoes

	hex_converter:
		movb	$4,	%cl
		ror	%cl,	%bh
		movb	$0x0F,	%ch	#valor de comparacao
		andb	%bh,	%ch	#fazendo and de 4 em 4 bits - digitos hexadecimais

		movb	$9,	%dh
		cmp	%dh,	%ch
		jg	hex_digit

		dec_digit:
			movb	$0x30,	%dh
			addb	%dh,	%ch
			jmp hex_converter_print

		hex_digit:
			movb	$0x0A,	%dh
			subb	%dh,	%ch
			movb	$0x41,	%dh
			addb	%dh,	%ch

		hex_converter_print:
			movb	%ch,	%al
			movb	$0x0E,	%ah
			int	$0x10

		decb	%dl
		jz	memory_size_end

		movb	$2,	%dh
		cmp	%dl,	%dh
		jne	hex_converter

		movb	%bl,	%bh
		jmp	hex_converter

	memory_size_end:
		popa
		ret

. = _start + 510
.byte		0X55, 0xAA
