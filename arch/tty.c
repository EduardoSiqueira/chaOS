/*Copyright © 2016

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

//grande parte desse conteudo foi retirado de: http://wiki.osdev.org/Meaty_Skeleton

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include <tty.h>
 
#include "vga.h"

//constantes indicando as dimensoes da tela e a saida de video mapeada em memoria
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

//variaveis que controlam a cor do terminal, assim como a posicao do cursor e um buffer do que foi escrito
static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

//funcao que inicializa o cursor e a tela do terminal
//retirado de: http://wiki.osdev.org/Meaty_Skeleton
void terminal_initialize(void) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

//funcao que move o terminal para cima
void terminal_scroll(void) {
	size_t y, x;
	for (y = 0; y < VGA_HEIGHT-1; y++) {
		for (x = 0; x < VGA_WIDTH; x++) {
			const size_t src = (y+1) * VGA_WIDTH + x;
			const size_t dest = y * VGA_WIDTH + x;

			terminal_buffer[dest] = vga_entry(terminal_buffer[src], terminal_color);
		}
	}

	//apos mover o conteudo para cima, apagamos a ultima linha para escrita
	terminal_row = VGA_HEIGHT - 1;
	for (size_t x = 0; x < VGA_WIDTH; x++) {
		const size_t index = y * VGA_WIDTH + x;
		terminal_buffer[index] = vga_entry(' ', terminal_color);
	}
}

//funcao que define a cor de background do terminal
//retirado de: http://wiki.osdev.org/Meaty_Skeleton
void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}
 
//funcao que escreve um byte na posicao recebida
//retirado de: http://wiki.osdev.org/Meaty_Skeleton
void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

//funcao que escreve um caracter na posicao atual do cursor
//retirado de: http://wiki.osdev.org/Meaty_Skeleton
void terminal_putchar(char c) {
	unsigned char uc = c;
	//tratando caracteres especiais(\n, \t, etc)
	switch(c) {
		case '\n':
			terminal_column = 0;
			if(++terminal_row == VGA_HEIGHT) terminal_scroll();
			break;
		case '\t':
			terminal_column += 4;
			if(terminal_column >= VGA_WIDTH) terminal_column = 0;
			break;
		default:
			terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);
			if (++terminal_column == VGA_WIDTH) {
				terminal_column = 0;
				if (++terminal_row == VGA_HEIGHT)
					terminal_scroll();
			}
	};
}

//funcao que escreve uma sequencia de dados, de tamanho size, na posicao atual do cursor
//retirado de: http://wiki.osdev.org/Meaty_Skeleton
void terminal_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++) {
		terminal_putchar(data[i]);
	}
}

//funcao que escreve uma string(sequencia de dados com um terminador '\0' no final) na posicao atual do cursor
//retirado de: http://wiki.osdev.org/Meaty_Skeleton
void terminal_writestring(const char* data) {
	terminal_write(data, strlen(data));
}
