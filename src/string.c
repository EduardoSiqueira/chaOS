
#include <string.h>

int strlen(const char * str){
	int size =0;
	while(str[size] != '\0'){
		++size;
	}
	return size;
}

void memcpy(void * mem1, const void * mem2, size_t n){
	int i;
	for (i = 0; i < n; ++i)
	{
		((char *)mem1)[i] = ((char*)mem2)[i];
	}
}

void strcpy(char * str1, const char * str2){
	int i = 0;
	while(str2[i] != '\0'){
		str1[i] = str2[i];
		++i;
	}
	str1[i] = '\0';
}

int strcmp(const char * str1, const char * str2){
	int i = 0;
	while(str1[i] != '\0' && str2[i] != '\0'){
		if(str1[i] > str2[i])return 1;
		else{
			if(str1[i] < str2[i])return -1;
			else{
				++i;
			}
		}
	}
	if(str1[i] == '\0' && str2[i] == '\0')return 0;
	else{
		if(str2[i] == '\0')return -1; 
		else return 1;
	}
}
