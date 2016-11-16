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

#include <stdio.h>
#include <stdint.h>

//funcao com assembly inline para mover o conteudo do cs para variavel que e
//retornada
uint16_t get_cs_content(void) {

	uint16_t content = 0;

	__asm__ __volatile__(
		"movw %%cs, %0"
		:"=a" (content)
	);

	return content;
}

//funcao com assembly inline para mover o conteudo do ds para variavel que e
//retornada
uint16_t get_ds_content(void) {

	uint16_t content = 0;

	__asm__ __volatile__(
		"movw %%ds, %0"
		:"=a" (content)
	);

	return content;
}

//funcao com assembly inline para mover o conteudo do ss para variavel que e
//retornada
uint16_t get_ss_content(void) {

	uint16_t content = 0;

	__asm__ __volatile__(
		"movw %%ss, %0"
		:"=a" (content)
	);

	return content;
}

//funcao que imprime conteudo dos registradores cs, ds e ss
//a impressao ocorre em valor binaro, decimal e hexadecimal
void print_registers(void) {
	uint16_t cs = get_cs_content();
	uint16_t ds = get_ds_content();
	uint16_t ss = get_ss_content();
	printf("Registers:\tBin\t  Dec\tHex\n\
	cs =\t%b\t%d\t%x\n\
	ds =\t%b\t%d\t%x\n\
	ss =\t%b\t%d\t%x\n", cs, cs, cs, ds, ds, ds, ss, ss, ss);
}
