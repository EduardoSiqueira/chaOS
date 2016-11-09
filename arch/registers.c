
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
	printf("Registers:\n\tcs = %d\n\tds = %d\n\tss = %d\n", get_cs_content(), get_ds_content(), get_ss_content());
}
