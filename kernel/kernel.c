
#include <stdio.h>

#include <tty.h>

void kernel_main() {

	terminal_initialize();
	printf("Kernel\n");
}
