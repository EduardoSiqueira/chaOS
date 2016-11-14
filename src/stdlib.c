#include <stdio.h>
#include <stdlib.h>
 
__attribute__((__noreturn__))
//funcao que trava a execucao do programa
void abort(void) {
	while (1) { }
}
