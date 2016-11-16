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
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <tty.h>

//funcao que converte um inteiro para uma string, para que possa ser imprimido corretamente
void itoa(int a, char *conv) {

    int digit = a % 10;
    if(a >= 10) itoa(a/10, conv);
    int index = strlen(conv);

    conv[index] = digit + '0';
    conv[index+1] = '\0';
}

//funcao que converte um inteiro para sua forma binaria, salva numa string
void itob(int a, char *conv) {

    int digit = a % 2;
    if(a >= 2) itob(a/2, conv);
    int index = strlen(conv);

    conv[index] = digit + '0';
    conv[index+1] = '\0';
}

//funcao que converte um inteiro para sua forma hexadecimal, salva numa string
void itohex(int a, char *conv) {

    int digit = a % 16;
    if(a >= 16) itohex(a/16, conv);
    int index = strlen(conv);

    if(digit <= 9) digit += '0';
    else {
        digit = (digit % 10) + 'A';
    }
    conv[index] = digit;
    conv[index+1] = '\0';
}

//funcao que imprime uma string de acordo com o formato recebido
//retorna a quantidade de caracteres imprimidos
int printf(const char *format, ...) {

	//inicializando a lista de argumentos
	va_list args;
	va_start(args, format);

	//variaveis que serao usadas
	int i = 0, chars_written = 0;
	char *str, c, buffer[32];

	//percorremos a string, procurando onde e como os argumentos tem que ser inseridos
	while(format[i] != '\0') {
		c = format[i];

		//encontrando um '%', temos que imprimir o proximo argumento recebido
		if(c == '%') {
			c = format[++i];
			switch(c) {
				//caso em que temos um caracter
				case 'c':
					/* va_arg nao aceita char como argumento */
					c = (char) va_arg(args, int);
					putchar(c);
					chars_written++;
					break;
				//caso em que temos uma string
				case 's':
					str = va_arg(args, char *);
					terminal_write(str, strlen(str));
					chars_written += strlen(str);
					break;
				//caso em que temos um inteiro, a ser imprimido em forma binaria
				case 'b':
					chars_written += printf("%s", "0b");
					c = va_arg(args, int);
					itob(c, buffer);
					terminal_write(buffer, strlen(buffer));
					chars_written += strlen(buffer);
					break;
				//caso em que temos um inteiro, a ser imprimido em forma decimal
				case 'd':
					c = va_arg(args, int);
					itoa(c, buffer);
					terminal_write(buffer, strlen(buffer));
					chars_written += strlen(buffer);
					break;
				//caso em que temos um inteiro, a ser imprimido em forma hexadecimal
				case 'x':
					chars_written += printf("%s", "0x");
					c = va_arg(args, int);
					itohex(c, buffer);
					terminal_write(buffer, strlen(buffer));
					chars_written += strlen(buffer);
					break;
			};
		//caso contrario, eh um caracter ordinario, e imprimimos normalmente
		} else {
			terminal_putchar(c);
			chars_written++;
		}

		i++; //incrementando o indice da string
		//reinicializando variaveis auxiliares
		str = NULL;
		buffer[0] = '\0';
		c = 0;
	}

	va_end(args);

	return chars_written; //retorna a quantidade de caracteres imprimidos
}

//funcao que imprime um caracter na tela
//retorna o caracter imprimido, convertido para inteiro
int putchar(int c) {
	terminal_putchar((char) c);
	return c;
}

//funcao que imprime uma string, com um newline no final
//retorna um numero nao-negativo em caso de sucesso
int puts(const char *s) {
	return printf("%s\n", s);
}
