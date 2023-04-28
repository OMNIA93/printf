#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 *  _printf - produces output according to a format
 *  @format: is a character string
 *
 *  Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int j = 0, sum = 0, x = 0;
	va_list data;

	va_start(data, format);
	while ((format != NULL) && format[j])
	{
		x = -1;
		if (format[j] == '%')
		{
			j++;
			if (!format[j])
				return (-1);
			if (format[j] == ' ' && !format[j + 1])
				return (-1);
			x = fun(data, format, j);
			while (format[j] == ' ' || format[j] == '#' || format[j] == '+')
				j++;
			if (format[j] == 'l' || format[j] == 'h')
				j++;
			if (x == -1)
				x = _putchar('%');
			else
				j++;
		}
		else
		{
			x = write(1, &format[j], 1);
			i++;
		}
		sum = sum + x;
	}
	va_end(data);
	if (format == NULL)
		sum = -1;
	return (sum);
}
