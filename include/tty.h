/* Copyright © 2016

Ali de França Husseinat         n°USP: 9292966 
Eduardo de Sousa Siqueira       n°USP: 9278299
Lucas Silva Marcondes           n°USP: 9293612
Ricardo Fernandes França do Vale    n°USP: 9293477 

This file is part of ChaOS.

ChaOS is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ChaOS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 

You should have received a copy of the GNU General Public License
along with ChaOS.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H
 
#include <stddef.h>
 
//funcao que inicializa o cursor e a tela do terminal
//retirado de: http://wiki.osdev.org/Meaty_Skeleton
void terminal_initialize(void);
//funcao que escreve um caracter na posicao atual do cursor
//retirado de: http://wiki.osdev.org/Meaty_Skeleton
void terminal_putchar(char c);
//funcao que escreve uma sequencia de dados, de tamanho size, na posicao atual do cursor
//retirado de: http://wiki.osdev.org/Meaty_Skeleton
void terminal_write(const char* data, size_t size);
//funcao que escreve uma string(sequencia de dados com um terminador '\0' no final) na posicao atual do cursor
//retirado de: http://wiki.osdev.org/Meaty_Skeleton
void terminal_writestring(const char* data);
 
#endif
