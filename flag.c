#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * space - print space
 * @format: string
 * @arg_list: argument list
 *
 * Return: number of characters
 */
int space(const char *format, va_list arg_list)
{
        int i = 0, x = 0, num;
        va_list copy;
        char c = format[i];

        va_copy(copy, arg_list);
        if (c == 'd' || c == 'i')
        {
                num = va_arg(copy, int);
                if (num >= 0)
                        x = _putchar(' ');
        }
        x += fun(arg_list, format, i);
        va_end(copy);
        return (x);
}

/**
 * hash - print hash
 * @format: string
 * @arg_list: argument list
 *
 * Return: number of characters
 */
int hash(const char *format, va_list arg_list)
{
        int i = 0, x = 0;
        va_list copy;
        unsigned int num;

        va_copy(copy, arg_list);
        num = va_arg(copy, unsigned int);
        if (num != 0)
        {
                x += _putchar('0');
                if (format[i] == 'x')
                        x += _putchar('x');
                if (format[i] == 'X')
                        x += _putchar('X');
                if (format[i] == 'b')
                        x += _putchar('b');
        }
        x += fun(arg_list, format, i);
        va_end(copy);
        return (x);
}

/**
 * plus - print plus
 * @format: string
 * @arg_list: argument list
 *
 * Return: number of characters
 */
int plus(const char *format, va_list arg_list)
{
        (void)format;
        (void)arg_list;
        return (print_int('+', arg_list));
}

/**
 * flag - select the flag
 * @format: string
 * @arg_list: argument list
 *
 * Return: number of characters
 */
int flag(const char *format, va_list arg_list)
{
        int i = 0, x = -1, s = 0, p = 0, h = 0;

        while (format[i])
        {
                if (!(format[i] == ' ' || format[i] == '#' || format[i] == '+'))
                        break;
                if (format[i] == ' ')
                        s = 1;
                if (format[i] == '#')
                        h = 1;
                if (format[i] == '+')
                        p = 1;
                i++;
        }
        if (s == 1 && (h == 1 || p == 1))
                s = 0;
        if (h == 1)
                x = hash(format, arg_list);
        if (p == 1)
                x = plus(format, arg_list);
        if (s == 1)
                x = space(format, arg_list);
        return (x);
}
