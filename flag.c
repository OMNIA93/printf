#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * space - print space
 * @format: string
 * @v: argument
 * @i: index
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
 * hash - print hash
 * @format: string
 * @i: index
 * @v: argument
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
/**
 * plus - print plus
 * @format: string
 * @i: index
 * @v: argument
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
 * flag - select the flag
 * @format: string
 * @i: index
 * @v: argument
 * Return: number of character
 */
int flag(const char *format, int i, va_list v)
{
	int x = -1, s = 0, p = 0, h = 0;

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
		x = hash(format, i, v);
	if (p == 1)
		x = plus(format, i, v);
	if (s == 1)
		x = space(format, i, v);
	return (x);
}
