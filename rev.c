#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * print_rev - check the code
 * @c: character
 * @v: argument
 * Return: len
 */

int print_rev(char c, va_list v)
{
	int len = 0, i = 0;
	char *s;
	char *p;
	(void)c;

	s = va_arg(v, char *);

	if (s == NULL)
	{
		s = "(null)";
		len = write(1, s, 6);
	}
	else
	{
		while (s[i])
		{
			len++;
			i++;
		}
		p = malloc(len);
		if (p != NULL)
		{
			for (i = 0; i < len; i++)
			{

				p[i] = s[len - 1 - i];
			}
			write(1, p, len);
		}
	}
	free(p);
	return (len);
}
