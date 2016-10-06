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

#string da versao do boot
bootVersion:
	.asciz "ChaOS v 0.1\n\r"
#strings para a impressao de dispositivos conectados
intro:
    .asciz "Dispositivos: \n\r"
success:
    .asciz "Dispositivo conectado\n\r"
failure:
    .asciz "Dispositivo nao conectado\n\r"
device_diskette:
    .asciz "FLoppy disk drive\n\r"
device_mc:
    .asciz "Math Coprocessor\n\r"
device_gp:
    .asciz "Game Port\n\r"


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
			movb    $0x31, %bl #valor de 1 na tabela ascii em hexadecimal eh colocado em bl 
			cmp     %bl, %al
			jne 	case_print_version
		
			#quando o 1 eh pressionado, a tela e limpada
			call clear_screen

			jmp loop

		#quando for apertada a tecla 2, a versao do boot sera impressa	
		case_print_version:
			movb	$0x32, %bl  #valor de 2 na tabela ascii em hexadecimal eh colocado em bl 
			cmp	    %bl, %al
			jne     case_check_devices
			
			#quando o 2 eh pressionado, imprime a versao do boot
			movw    $bootVersion, %bx #posicao do inicio da mensagem da versao
			call print_str
			
			jmp loop

		#quando for apertada a tecla 3, sao impressos 3 dispositivos e eh informado se estao conectados ou nao	
        case_check_devices:
			movb	$0x33, %bl  #valor de 3 na tabela ascii em hexadecimal eh colocado em bl 
			cmp	    %bl, %al
			jne     default
			
			#quando o 3 eh pressionado, imprime dispostivos conectados
			call    check_devices
			
			jmp loop



		default:
		        #printar um caracter(contido no registrador %al)
		        movb	$0x0E,	%ah
		        int	$0x10		#interrupt de video

		        jmp	loop
print_newline:
		movb	$0x0A,	%al	#newline - '\n'
		movb	$0x0E,	%ah
		int	$0x10

		movb	$0x0D,	%al
		int	$0x10

		ret

clear_screen:
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

		ret

print_str:	
        movb    $0x00, %dl #'\0' em ascii
                
		print_str_loop:
            movb    (%bx), %al #obtem o caracter contido na posicao bx da memoria
                        
			#finaliza a impressao caso chegue ao '\0'
			cmp     %al, %dl
                        je     print_str_end
                       
                        #printar um caracter(contido no registrador %al)
			movb    $0x0E,  %ah
                        int     $0x10           #interrupt de video
			
                        inc     %bx #incrementa o endereco da mensagem
			
			jmp 	print_str_loop 
			
	    print_str_end:
            ret

check_devices:
        movw    $intro, %bx
        call    print_str
        #interrupcao usada para verificar listagem de dispositivos conectados
        int     $0x11
        #copia do resultado da interrupcao
        movw    %ax, %bx
        #verificacao do floppy disk drive
        andw    $0x0001, %bx
        #printando mensagem para disquete
        movw    $device_diskette, %bx
        call    print_str
        #verificando se dipositivo esta concectado 
        movw    $0x0001, %cx
        cmpw     %bx, $cx
        ceq     print_success
        movw    $0x0000, %cx
        cmpw     %bx, $cx
        ceq     print_failure
        ret


print_success: #impressao de mensagem de dispositivo encontrado
        movw    $success, %bx
        call    print_str
        ret

print_failure: #impressao de mensagem de dispositvo nao encontrado
        movw    $failure, %bx
        call    print_str
        ret


    
. = _start + 510
.byte		0X55, 0xAA
