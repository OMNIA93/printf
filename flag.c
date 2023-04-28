#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * space - print space
 * @format: string
 * @v: argument
 * @i: index
 *
 * Return: number of character
 */

int space(const char *format, int i, va_list v)
{
	int x = 0;
	va_list copy;
	int num;
	char c = format[i];

	va_copy(copy, v);
	if (c == 'd' || c == 'i')
	{
		num = va_arg(copy, int);
		if (num >= 0)
			x = _putchar(' ');
	}
	x = x + fun(v, format, i);
	va_end(copy);
	return (x);
}



/**
 * plus - print plus
 * @format: string
 * @i: index
 * @v: argument
 *
 * Return: number of character
 */
int plus(const char *format, int i, va_list v)
{
	int x = 0;
	(void)format;
	(void)i;

	x = print_int('+', v);
	return (x);
}



/**
 * hash - print hash
 * @format: string
 * @i: index
 * @v: argument
 *
 * Return: number of character
 */

int hash(const char *format, int i, va_list v)
{
	int x = 0;
	va_list copy;
	unsigned int num;

	va_copy(copy, v);
	num = va_arg(copy, unsigned int);
	if (num != 0)
	{
		x = x + _putchar('0');
		if (format[i] == 'x')
			x = x + _putchar('x');
		if (format[i] == 'X')
			x = x + _putchar('X');
		if (format[i] == 'b')
			x = x + _putchar('b');
	}
	x = x + fun(v, format, i);
	va_end(copy);
	return (x);
}
