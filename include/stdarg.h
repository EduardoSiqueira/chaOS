
#ifndef _STDARG_H
#define _STDARG_H

typedef __builtin_va_list va_list;

#define va_start(ap, last_arg) __builtin_va_start(ap, last_arg)
#define va_end(ap) __builtin_va_end(ap)
#define va_arg(v, l) __builtin_va_arg(v,l)

#endif
