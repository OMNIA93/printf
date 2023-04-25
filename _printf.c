#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Prints formatted output to stdout.
 * @format: A pointer to a string of format arguments.
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    putchar('%');
                    putchar(format[i]);
                    count += 2;
                    break;
            }
        }
        else
        {
            putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);

    return count;
}
