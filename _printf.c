#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Prints a formatted output to stdout.
 *
 * @format: A character string that contains zero or more directives.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;

                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;

                case '%':
                    putchar('%');
                    count++;
                    break;

                default:
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
