#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * istring - print string
 * @c: character
 * @v: argument
 * Return: number of bytes
 */
int istring(char c, va_list v)
{
	int i = 0;
	int length = 0;
	int x = 0;
	char *s;
	char n;


	if (c == '%')
	{
		n = '%';
		x = write(1, &n, 1);
		return (x);
	}
	if (c == 's')
	{
		s = va_arg(v, char*);
		if (s != NULL)
		{
			while (s[i])
			{
				length++;
				i++;
			}
			x = write(1, s, length);
		}
		else
		{
			s = "(null)";
			x = write(1, s, 6);
		}
	}
	else
	{
		n = va_arg(v, int);
		x = write(1, &n, 1);

	}

	return (x);
}


/**
 * hexa - convert to hexa
 * @c: charachter
 */
void hexa(char c)
{
	int i, n = 1, a, temp, size = 0;
	char s[2];

	i = (int)c;
	temp = i;
	while (temp)
	{
		size++;
		temp = temp / 16;
	}
	if (size == 1)
	{
		_putchar('0');
		a = i % 16;
		if (a >= 10 && a < 16)
		{
			a = a % 10;
			_putchar('A' + a);
		}
		else
			_putchar('0' + a);
	}
	else
	{
		while (n >= 0)
		{
			a = i % 16;
			if (a >= 10 && a < 16)
			{
				a = a % 10;
				s[n] = ('A' + a);
			}
			else
				s[n] = ('0' + a);
			i = i / 16;
			n--;
		}
		write(1, s, 2);
	}
}


/**
 * print_string -  prints the string
 * @c: character to compare with
 * @v: argument
 * Return: number of charachters
 */
int print_string(__attribute__((unused))char c, va_list v)
{
	char *s;
	int i = 0, size = 0, j = 0, size1 = 0;

	s = va_arg(v, char *);
	if (s == NULL)
	{
		s = "(null)";
		size1 = write(1, s, 6);
	}
	else
	{
		while (s[i])
		{
			if (((s[i] > 0) && (s[i] < 32)) || s[i] >= 127)
				size1 = size1 + 3;
			size1++;
			size++;
			i++;
		}
		while (j < size)
		{
			if (((s[j] > 0) && (s[j] < 32)) || s[j] >= 127)
			{
				_putchar('\\');
				_putchar('x');
				hexa(s[j]);
			}
			else
				_putchar(s[j]);
			j++;
		}
	}
	return (size1);
}
