#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_rev - prints a string in reverse
 * @r: string to print
 * Return: number of chars printed
 */
int print_rev1(va_list r)
{
        char *st;
        int i = 0, j = 0;

        st = va_arg(r, char *);
        if (st == NULL)
                st = ")llun(";
        while (st[i])
                i++;
        while (i--)
        {
                _putchar(st[i]);
                j++;
        }
        return (j);
}
