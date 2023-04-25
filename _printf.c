#include "main.h"
#include <stdio.h>

/**
 * _printf - Produces output according to a format.
 * @format: A pointer to a string that contains zero or more format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            if (*format == 'c')
            {
                int c = va_arg(args, int);
                putchar(c);
                printed_chars++;
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                if (s == NULL)
                    s = "(null)";
                while (*s != '\0')
                {
                    putchar(*s);
                    s++;
                    printed_chars++;
                }
            }
            else if (*format == '%')
            {
                putchar('%');
                printed_chars++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                int negative = 0;

                if (num < 0)
                {
                    negative = 1;
                    num = -num;
                }

                int num_digits = 0;
                int num_copy = num;
                do
                {
                    num_digits++;
                    num_copy /= 10;
                } while (num_copy != 0);

                if (negative)
                {
                    putchar('-');
                    printed_chars++;
                }

                do
                {
                    int digit = num % 10;
                    putchar('0' + digit);
                    printed_chars++;
                    num /= 10;
                } while (num != 0);

            }
            else
            {
                putchar('%');
                putchar(*format);
                printed_chars += 2;
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }
        format++;
    }

    va_end(args);

    return (printed_chars);
}
