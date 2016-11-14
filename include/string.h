
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
