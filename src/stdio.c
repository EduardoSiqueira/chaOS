#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <tty.h>

int puts(const char* string) {
    return printf("%s\n", string);
}

int putchar(int ic) {
    char c = (char) ic;
    terminal_write(&c, sizeof(c));
    return ic;
}

static bool print(const char* data, size_t length) {
    const unsigned char* bytes = (const unsigned char*) data;
    size_t i;
    for (i = 0; i < length; i++)
        if (putchar(bytes[i]) == EOF)
            return FALSE;
    return TRUE;
}

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

int printf(const char* format, ...) {
    va_list parameters;
    va_start(parameters, format);

    int written = 0;

    while (*format != '\0') {
        size_t maxrem = 2147483647 - written;

        if (format[0] != '%' || format[1] == '%') {
            if (format[0] == '%')
                format++;
            size_t amount = 1;
            while (format[amount] && format[amount] != '%')
                amount++;
            if (maxrem < amount) {
                return -1;
            }
            if (!print(format, amount))
                return -1;
            format += amount;
            written += amount;
            continue;
        }

        const char* format_begun_at = format++;

        if (*format == 'c') {
            format++;
            char c = (char) va_arg(parameters, int);
            if (!maxrem) {
                return -1;
            }
            if (!print(&c, sizeof(c)))
                return -1;
            written++;
        } else if (*format == 's') {
            format++;
            const char* str = va_arg(parameters, const char*);
            size_t len = strlen(str);
            if (maxrem < len) {
                return -1;
            }
            if (!print(str, len))
                return -1;
            written += len;
        } else if (*format == 'd') {
            format++;
            int integer = va_arg(parameters, int);
            char converted[32] = {'\0'} ;
            itoa(integer, converted);
            size_t len = strlen(converted);
            if (maxrem < len) {
                return -1;
            }
            if (!print(converted, len))
                return -1;
            written += len;
        } else if (*format == 'b') {
            format++;
            int integer = va_arg(parameters, int);
            char converted[32] = {'\0'} ;
            itob(integer, converted);
            size_t len = strlen(converted);
            if (maxrem < len) {
                return -1;
            }
            if (!print(converted, len))
                return -1;
            written += len;
        } else if (*format == 'x') {
            format++;
            int integer = va_arg(parameters, int);
            char converted[32] = {'\0'} ;
            itohex(integer, converted);
            size_t len = strlen(converted);
            if (maxrem < len) {
                return -1;
            }
            if (!print(converted, len))
                return -1;
            written += len;
        
        } else {
            format = format_begun_at;
            size_t len = strlen(format);
            if (maxrem < len) {
                return -1;
            }
            if (!print(format, len))
                return -1;
            written += len;
            format += len;
        }
    }

    va_end(parameters);
    return written;
}
