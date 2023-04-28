#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * flag - select the flag
 * @format: string
 * @i: index
 * @v: argument
 *
 * Return: number of character
 */
int flag(const char *format, int i, va_list v)
{
	int x = -1, s = 0, p = 0, h = 0;

		while (format[i])
		{
	      if (!(format[i] == ' ' || format[i] == '#' || format[i] == '+'))
		break;
		if (format[i] == '#')
			h = 1;
		if (format[i] == ' ')
			s = 1;
		if (format[i] == '+')
			p = 1;
		i++;
	}
	if (h == 1)
		x = hash(format, i, v);
	if (s == 1 && (h == 1 || p == 1))
		s = 0;
	if (s == 1)
		x = space(format, i, v);
	if (p == 1)
		x = plus(format, i, v);
	return (x);
}
