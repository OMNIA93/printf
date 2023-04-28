#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * print_unsign - unsigned
 * @c: character
 * @v: argument
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
 * print_hexa - hexa
 * @c: character
 * @v: argument
 *
 * Return: number of bytes
 */
int print_hexa(char c, va_list v)
{
	int i = 0, b;
	unsigned long int n, a, num;
	char *s;

	if (c == 'l')
		n = va_arg(v, unsigned long int);
	else if (c == 'h')
		n = (unsigned short)va_arg(v, int);
	else
		n = va_arg(v, unsigned int);
	if (n == 0)
		return (_putchar('0'));
	num = n;
	while (num)
	{
		i++;
		num = num / 16;
	}
	s = malloc(i);
	if (s == NULL)
		return (0);
	b = i - 1;
	while (b >= 0)
	{
		a = n % 16;
		if (a >= 10 && a < 16)
		{
			a = a % 10;
			s[b] = 'a' + a;
		}
		else
			s[b] = '0' + (n % 16);
		n = n / 16;
		b--;
	}
	write(1, s, i);
	free(s);
	return (i);
}
/**
 * print_Hexa - hexa
 * @c: character
 * @v: argument
 *
 * Return: number of bytes
 */
int print_Hexa(char c, va_list v)
{
	int i = 0, b;
	unsigned long int n, a, num;
	char *s;

	if (c == 'l')
		n = va_arg(v, unsigned long int);
	else if (c == 'h')
		n = (unsigned short)va_arg(v, int);
	else
		n = va_arg(v, unsigned int);
	if (n == 0)
		return (_putchar('0'));
	num = n;
	while (num)
	{
		i++;
		num = num / 16;
	}
	s = malloc(i);
	if (s == NULL)
		return (0);
	b = i - 1;
	while (b >= 0)
	{
		a = n % 16;
		if (a >= 10 && a < 16)
		{
			a = a % 10;
			s[b] = 'A' + a;
		}
		else
			s[b] = '0' + (n % 16);
		n = n / 16;
		b--;
	}
	write(1, s, i);
	free(s);
	return (i);
}
