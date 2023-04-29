#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


/**
 * print_unsign - unsigned
 * @c: character
 * @v: argument
 *
 * Return: number of bytes
 */

int print_unsign(char c, va_list v)
{
	int i = 0, b;
	unsigned long int n, num;
	char *s;

	if (c == 'l')
		n = va_arg(v, unsigned long int);
	else if (c == 'h')
		n = (unsigned short)va_arg(v, int);
	else
		n = va_arg(v, unsigned int);
	if (n == 0)
	{
		c = '0';
		i = write(1, &c, 1);
		return (i);
	}
	num = n;
	while (num)
	{
		i++;
		num = num / 10;
	}
	s = malloc(i);
	if (s == NULL)
		return (0);

	b = i - 1;
	while (b >= 0)
	{
		s[b] = '0' + (n % 10);
		n = n / 10;
		b--;
	}
	write(1, s, i);
	free(s);
	return (i);
}


/**
 * print_oct - octal
 * @c: character
 * @v: argument
 *
 * Return: number of bytes
 */
int print_oct(char c, va_list v)
{
	int i = 0, a;
	unsigned long int n, num;
	char *arr;

	if (c == 'l')
		n = va_arg(v, unsigned long int);
	else if (c == 'h')
		n = (unsigned short)va_arg(v, int);
	else
		n = va_arg(v, unsigned int);
	if (n == 0)
	{
		c = '0';
		i = write(1, &c, 1);
		return (i);
	}
	num = n;
	while (num)
	{
		i++;
		num = num / 8;
	}
	arr = malloc(i);
	if (!arr)
		return (0);
	a = i - 1;
	while (a >= 0)
	{
		arr[a] = '0' + (n % 8);
		n = n / 8;
		a--;
	}
	write(1, arr, i);
	free(arr);
	return (i);
}


/**
 * print_P - print pointer
 * @c: character
 * @v: argument
 *
 * Return: number of bytes
 */

int print_P(char c, va_list v)
{
	char buff[1024];
	void *ptr = va_arg(v, void *);
	int l;
	(void)c;

	l = sprintf(buff, "%p", ptr);

	write(1, buff, l);
	return (l);

	ptr = malloc(1024);
	free(ptr);
	return (write(1, &ptr, 8));
}
