#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * rot - printrot13
 * @c: character
 * @v: argument
 * Return: number of bytes
 */
int rot(__attribute__((unused))char c, va_list v)
{
	int i = 0, x = 0, length = 0;
	char *s, *p;

	s = va_arg(v, char *);
	if (s != NULL)
	{
		while (s[i])
		{
			length++;
			i++;
		}
		i = 0;
		p = malloc(length);
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
