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


/**
 * rot - printrot13
 * @c: character
 *
 * @v: argument
 * Return: number of bytes
 */
int rot(__attribute__((unused))char c, va_list v)
{
	int i = 0, len = 0, x = 0;
	char *s, *p;

	s = va_arg(v, char *);
	if (s != NULL)
	{
		while (s[i])
		{
			len++;
			i++;
		}
		i = 0;
		p = malloc(len);
		if (p != NULL)
		{
			while (s[i])
			{
				if (s[i] >= 97 && s[i] <= 109)
					p[i] = s[i] + 13;
				else if (s[i] >= 65 && s[i] <= 77)
					p[i] = s[i] + 13;
				else if (s[i] > 77)
					p[i] = s[i] - 13;
				i++;
			}
		}
		x = write(1, p, length);
	}
	else
	{
		s = "(null)";
		x = write(1, s, 6);
	}
	free(p);
	return (x);
}
