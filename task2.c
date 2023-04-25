#include <main.h>

int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    va_start(args, format);

    while (*format != '') {
        if (*format == '%') {
            format++;
            if (*format == 'b') {
                unsigned int value = va_arg(args, unsigned int);
                int bits = sizeof(unsigned int) * 8;
                for (int i = bits - 1; i >= 0; i--) {
                    putchar((value & (1 << i)) ? '1' : '0');
                    count++;
                }
            } else {
                putchar('%');
                count++;
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
