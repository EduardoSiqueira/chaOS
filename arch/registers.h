/*Copyright © 2016

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
#ifndef _REGISTERS_H
#define _REGISTERS_H

#include <stdint.h>

//funcao com assembly inline para mover o conteudo do cs para variavel que e retornada
uint16_t get_cs_content(void);

//funcao com assembly inline para mover o conteudo do ds para variavel que e retornada
uint16_t get_ds_content(void);

//funcao com assembly inline para mover o conteudo do ss para variavel que e retornada
uint16_t get_ss_content(void);

//funcao que imprime conteudo dos registradores cs, ds e ss
//a impressao ocorre em valor binaro, decimal e hexadecimal
void print_registers(void);

#endif
