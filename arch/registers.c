
#include <stdio.h>
#include <stdint.h>

uint16_t get_cs_content(void) {

	uint16_t content = 0;

	__asm__ __volatile__(
		"movw %%cs, %0"
		:"=a" (content)
	);

	return content;
}

uint16_t get_ds_content(void) {

	uint16_t content = 0;

	__asm__ __volatile__(
		"movw %%ds, %0"
		:"=a" (content)
	);

	return content;
}

uint16_t get_ss_content(void) {

	uint16_t content = 0;

	__asm__ __volatile__(
		"movw %%ss, %0"
		:"=a" (content)
	);

	return content;
}

void print_registers(void) {
	uint16_t cs = get_cs_content();
	uint16_t ds = get_ds_content();
	uint16_t ss = get_ss_content();
	printf("Registers:\tBin\t  Dec\tHex\n\
	cs =\t%b\t%d\t%x\n\
	ds =\t%b\t%d\t%x\n\
	ss =\t%b\t%d\t%x\n", cs, cs, cs, ds, ds, ds, ss, ss, ss);
}
