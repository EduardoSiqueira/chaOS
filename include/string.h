
#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>

int strlen(const char * str);

void memcpy(void * mem1, const void * mem2, size_t n);

void strcpy(char * str1, const char * str2);

int strcmp(char * str1, char * str2);

#endif
