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
