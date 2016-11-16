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
#ifndef _STDIO_H
#define _STDIO_H

//definimos o EOF pois ele pode ser usado como codigo de erro para as funcoes abaixo
#define EOF (-1)

//funcao que imprime uma string de acordo com o formato recebido
//retorna a quantidade de caracteres imprimidos
int printf(const char* , ...);
//funcao que imprime um caracter na tela
//retorna o caracter imprimido, convertido para inteiro
int putchar(int);
//funcao que imprime uma string, com um newline no final
//retorna um numero nao-negativo em caso de sucesso
int puts(const char*);
 
#endif
