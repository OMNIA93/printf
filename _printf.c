#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int len = 0; /* length of printed string */
    va_list args; /* argument list */
    char c;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    c = (char) va_arg(args, int);
                    len += _putchar(c);
                    break;
                case 's':
                    len += _puts(va_arg(args, char *));
                    break;
                case '%':
                    len += _putchar('%');
                    break;
                default:
                    len += _putchar('%');
                    len += _putchar(*format);
                    break;
            }
        }
        else
        {
            len += _putchar(*format);
        }
        format++;
    }

    va_end(args);

    return (len);
}
