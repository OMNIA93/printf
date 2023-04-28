#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * get_number - get
 * @c: is a character
 * @v: argument
 * Return: number
 */
long int get_number(char c, va_list v)
{
	long int n;

	if (c == 'l')
		n = va_arg(v, long int);
	else if (c == 'h')
		n = (short int)va_arg(v, int);
	else
		n = va_arg(v, int);
	return (n);
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


/**
 * print_int - print integer
 * @c: is a character
 * @v: argument
 * Return: number
 */

int print_int(char c, va_list v)
{
	long int i = 0, n, num, decimal = 1, a = 0, min;

	min = get_min(c);
	n = get_number(c, v);
	if (n < 0)
	{
		_putchar('-');
		i++;
		if (n == min)
		{
			n = (n + 1) * -1;
			a = 1;
		}
		else
			n = n * -1;
	}
	else if (n >= 0 && c == '+')
		i = i +  _putchar('+');
	if (n < 10 && c == '+')
		return (i = i + _putchar(n + '0'));
	num = n;
	while (num > 9)
	{
		decimal *= 10;
		num /= 10;
		i++;
	}
	while (decimal >= 1)
	{
		if ((decimal == 1) && (a == 1))
			_putchar((n / decimal) + 1 + '0');
		else
			_putchar((n / decimal) + '0');
		n = n % decimal;
		decimal /= 10;
	}
	i++;
	return (i);
}
