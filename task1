#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;
    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'd' || *format == 'i') {
                int arg = va_arg(args, int);
                count += printf("%d", arg);
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}
