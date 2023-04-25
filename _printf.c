#include "main.h"
#include <stdio.h>

/**
 * _printf - prints formatted output to stdout
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char c;
    char *s;
    int d;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
            case 'c':
                c = va_arg(args, int);
                putchar(c);
                count++;
                break;
            case 's':
                s = va_arg(args, char *);
                while (*s != '\0')
                {
                    putchar(*s);
                    s++;
                    count++;
                }
                break;
            case '%':
                putchar('%');
                count++;
                break;
            case 'd':
            case 'i':
                d = va_arg(args, int);
                printf("%d", d);
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
