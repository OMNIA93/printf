#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
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
	int i = 0, n = 0, x = -1;
	char c;

	c = format[k];
	while ((n < 11) && c)
	{
		i = 0;
		while ((sp[n].c)[i])
		{
			if ((sp[n].c)[i] == c)
				x = sp[n].p(c, v);
			i++;
		}
		n++;
	}
	if (x == -1)
		x = flag(format, k, v);
	if (x == -1)
		x = print_l(format, k, v);
	return (x);
}


/**
 * print_l -  print string
 * @format:  string that will print
 * @i: index
 *
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
