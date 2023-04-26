#include "main.h"

/**
 * _printf - Prints formatted output to stdout
 * @format: Format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char c;

    va_start(args, format);

    while ((c = *format++) != '\0')
    {
        if (c == '%')
        {
            switch (*format++)
            {
                case 'c':
                    count += write(1, (char[]){(char)va_arg(args, int)}, 1);
                    break;
                case 's':
                    count += write(1, va_arg(args, char*), strlen(va_arg(args, char*)));
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                default:
                    count += write(1, "%", 1);
                    count += write(1, &c, 1);
                    break;
            }
        }
        else
        {
            count += write(1, &c, 1);
        }
    }

    va_end(args);

    return count;
}
