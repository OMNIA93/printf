#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 * fun - get the function
 * @format: character to compare with
 * @v: argument
 * @k: index
 * Return: 1 if it is founded
 */
int fun(va_list v, const char *format, int k)
{
	spec sp[] = {
		{"sc%", 1, istring}, {"di", 1, print_int}, {"b", 1, binary},
		{"u", 1, print_unsign}, {"o", 1, print_oct}, {"S", 1, print_string},
		{"x", 1, print_hexa}, {"p", 1, print_P}, {"X", 1, print_Hexa},
		{"R", 1, rot}, {"r", 1, print_rev}
	};
	int i = 0, j = 0, x = -1;
	char c;

	c = format[k];
	while ((j < 11) && c)
	{
		i = 0;
		while ((sp[j].c)[i])
		{
			if ((sp[j].c)[i] == c)
				x = sp[j].p(c, v);
			i++;
		}
		j++;
	}
	if (x == -1)
		x = flag(format, k, v);
	if (x == -1)
		x = print_l(format, k, v);
	return (x);
}
/**
 *  _printf - produces output according to a format
 *  @format: is a character string
 *  Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, sum = 0, x = 0;
	va_list data;

	va_start(data, format);
	while ((format != NULL) && format[i])
	{
		x = -1;
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
			if (format[i] == ' ' && !format[i + 1])
				return (-1);
			x = fun(data, format, i);
			while (format[i] == ' ' || format[i] == '#' || format[i] == '+')
				i++;
			if (format[i] == 'l' || format[i] == 'h')
				i++;
			if (x == -1)
				x = _putchar('%');
			else
				i++;
		}
		else
		{
			x = write(1, &format[i], 1);
			i++;
		}
		sum = sum + x;
	}
	va_end(data);
	if (format == NULL)
		sum = -1;
	return (sum);
}
