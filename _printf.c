#include <stdio.h>
#include <stdarg.h>
#include "main.h"


/**
 * _printf - prints a formatted string to the standard output stream
 * @format: format string
 *
 * Return: number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				int c = va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				fputs(s, stdout);
				count += strlen(s);
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);
	return (count);
}

/**
 * fputs - writes a string to the specified stream up to but not including the null character
 * @str: string to write
 * @stream: file pointer
 *
 * Return: number of characters written on success, or EOF on error
 */
int fputs(const char *str, FILE *stream)
{
	int count = 0;

	if (!str || !stream)
		return (EOF);

	while (*str)
	{
		if (fputc(*str, stream) == EOF)
			return (EOF);

		count++;
		str++;
	}

	return (count);
}
