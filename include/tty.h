
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
