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
#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>

//funcao que retorna o tamanho de uma string, excluindo o terminador
int strlen(const char * str);

//funcao que copia um trecho de memoria, de tamanho n, para outro
void memcpy(void * mem1, const void * mem2, size_t n);

//funcao que copia uma string para outra
void strcpy(char * str1, const char * str2);

//funcao que compara duas strings
//retorna 0 caso sejam iguais, um positivo caso a primeira seja maior(ordem alfabetica ou tamanho), ou um negativo caso seja menor
int strcmp(const char * str1, const char * str2);

#endif
