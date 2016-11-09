
#include <stdio.h>
#include <../arch/registers.h>
#include <tty.h>

void kernel_main() {

	terminal_initialize();
	printf("ChaOS v0.0\nWelcome.");
}
