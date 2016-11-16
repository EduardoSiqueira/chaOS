/* Copyright © 2016

Ali de França Husseinat         n°USP: 9292966 
Eduardo de Sousa Siqueira       n°USP: 9278299
Lucas Silva Marcondes           n°USP: 9293612
Ricardo Fernandes França do Vale    n°USP: 9293477 

This file is part of ChaOS.

ChaOS is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ChaOS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 

You should have received a copy of the GNU General Public License
along with ChaOS.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _STDARG_H
#define _STDARG_H

/* as definicoes da lista de argumentos variaveis sao feitas com base nas funcionalidades built-in do gcc */
typedef __builtin_va_list va_list;

#define va_start(vl, last_arg) __builtin_va_start(vl, last_arg)
#define va_end(vl) __builtin_va_end(vl)
#define va_arg(v, t) __builtin_va_arg(v,t)

#endif
