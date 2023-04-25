#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int count = 0;
    char c;
    while ((c = *format++) != '') {
        if (c == '%') {
            switch (*format++) {
                case 'c': {
                    int arg = va_arg(args, int);
                    putchar(arg);
                    count++;
                    break;
                }
                case 's': {
                    char *arg = va_arg(args, char *);
                    while (*arg != '') {
                        putchar(*arg++);
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
            }
        } else {
            putchar(c);
            count++;
        }
    }
    va_end(args);
    return count;
}
