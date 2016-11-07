#include<stdio.h>
#include <stddef.h>
int strlen(char * str){
	int size =0;
	while(str[size] != '\0'){
		++size;
	}
	return size;
}
int strcmp(char * str1, char * str2){
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
int main(int argc, char const *argv[])
{
	printf("%d\n", strcmp("ab", "ab"));
	return 0;
}