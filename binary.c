#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * binary - convert unsigned int to binary
 * @c: character
 * @v: argument
 * Return: number of bytes
 */
int binary(__attribute__((unused))char c, va_list v)
{
	unsigned int b;
	unsigned int temp;
	char *s;
	int length = 0;
	int i;
	char n;


	b = va_arg(v, unsigned int);
	if (b == 0)
	{
		n = '0';
		length = write(1, &n, 1);
		return (length);
	}
	temp = b;
	while (temp)
	{
		length++;
		temp = temp / 2;
	}
	s = malloc(length);
	if (s == NULL)
		return (0);

	i = length - 1;
	while (i >= 0)
	{
		s[i] = '0' + (b % 2);
		b = b / 2;
		i--;
	}
	write(1, s, length);
	free(s);
	return (length);
}
