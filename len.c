#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * print_l -  print string
 * @format:  string that will print
 * @i: index
 * @v: argument
 *
 * Return: number of bytes
 */
int print_l(const char *format, int i, va_list v)
{
	int x = -1;

	if (format[i + 1] && (format[i] == 'l' || format[i] == 'h'))
	{
		if (format[i + 1] == 'd')
			x = print_int(format[i], v);
		if (format[i + 1] == 'i')
			x = print_int(format[i], v);
		if (format[i + 1] == 'u')
			x = print_unsign(format[i], v);
		if (format[i + 1] == 'o')
			x = print_oct(format[i], v);
		if (format[i + 1] == 'x')
			x = print_hexa(format[i], v);
		if (format[i + 1] == 'X')
			x = print_Hexa(format[i], v);
	}
	return (x);
}
