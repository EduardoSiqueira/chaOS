#ifndef _STDINT_H
#define _STDINT_H

//para garantir que os tamanhos sao o que desejamos, definimos diferentes tipos para cada arquitetura
#if defined(__i386__)
	#include <../arch/stdint.h>
#endif

#endif
