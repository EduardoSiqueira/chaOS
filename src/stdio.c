
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <tty.h>

void itoa(int a, char *conv) {

    int digit = a % 10;
    if(a >= 10) itoa(a/10, conv);
    int index = strlen(conv);

    conv[index] = digit + '0';
    conv[index+1] = '\0';
}

void itob(int a, char *conv) {

    int digit = a % 2;
    if(a >= 2) itob(a/2, conv);
    int index = strlen(conv);

    conv[index] = digit + '0';
    conv[index+1] = '\0';
}

void itohex(int a, char *conv) {

    int digit = a % 16;
    if(a >= 16) itohex(a/16, conv);
    int index = strlen(conv);

    if(digit <= 9) digit += '0';
    else {
        digit = (digit % 10) + 'A';
    }
    conv[index] = digit;
    conv[index+1] = '\0';
}

int printf(const char *format, ...) {

	va_list args;
	va_start(args, format);
	int i = 0, chars_written = 0;
	char *str, c, buffer[32];

	while(format[i] != '\0') {
		c = format[i];

		if(c == '%') {
			c = format[++i];
			switch(c) {
				case 'c':
					c = (char) va_arg(args, int);
					putchar(c);
					chars_written++;
					break;
				case 's':
					str = va_arg(args, char *);
					terminal_write(str, strlen(str));
					chars_written += strlen(str);
					break;
				case 'b':
					chars_written += printf("%s", "0b");
					c = va_arg(args, int);
					itob(c, buffer);
					terminal_write(buffer, strlen(buffer));
					chars_written += strlen(buffer);
					break;
				case 'd':
					c = va_arg(args, int);
					itoa(c, buffer);
					terminal_write(buffer, strlen(buffer));
					chars_written += strlen(buffer);
					break;
				case 'x':
					chars_written += printf("%s", "0x");
					c = va_arg(args, int);
					itoa(c, buffer);
					terminal_write(buffer, strlen(buffer));
					chars_written += strlen(buffer);
					break;
			};
		} else {
			terminal_putchar(c);
			chars_written++;
		}

		i++;
		str = NULL;
		buffer[0] = '\0';
		c = 0;
	}

	va_end(args);

	return chars_written;
}

int putchar(int c) {
	terminal_putchar((char) c);
	return c;
}

int puts(const char *s) {
	return printf("%s\n", s);
}
