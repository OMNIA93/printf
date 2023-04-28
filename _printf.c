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
 *
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
	int i, j, x = -1;
	char c;

	c = format[k];
	for (j = 0; j < 11 && c; j++)
	{
		for (i = 0; sp[j].c[i]; i++)
		{
			if (sp[j].c[i] == c)
				x = sp[j].p(c, v);
		}
	}
	if (x == -1)
		x = flag(format, k, v);
	if (x == -1)
		x = print_l(format, k, v);
	return (x);
}


/**
 *  _printf - produces output according to a format
 *  @format: character string
 *
 *  Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, sum = 0, x = 0;
	va_list data;

	va_start(data, format);
	for (i = 0; format && format[i]; i++)
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
			for (; format[i] == ' ' || format[i] == '#' || format[i] == '+'; i++)
				;
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
		}
		sum += x;
	}
	va_end(data);
	if (!format)
		sum = -1;
	return (sum);
}

