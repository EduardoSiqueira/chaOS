
#ifndef _STDARG_H
#define _STDARG_H

/* as definicoes da lista de argumentos variaveis sao feitas com base nas funcionalidades built-in do gcc */
typedef __builtin_va_list va_list;

#define va_start(vl, last_arg) __builtin_va_start(vl, last_arg)
#define va_end(vl) __builtin_va_end(vl)
#define va_arg(v, t) __builtin_va_arg(v,t)

#endif
