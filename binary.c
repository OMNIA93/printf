#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * binary - convert unsigned int to binary
 * @c: character
 * @v: argument
 *
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

/**
 * print_hexa - hexa
 * @c: character
 *
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
 *
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


/**
 * get_min - git
 * @c: is a character
 *
 * Return: number
 */

long int get_min(char c)
{
	long int n;

	if (c == 'l')
		n = LONG_MIN;
	else if (c == 'h')
		n = -32768;
	else
		n = -2147483648;
	return (n);
}
