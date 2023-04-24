#include "main.h"
/**
 * _printf - function that produces output according to a format.
 *
 * @format:  character string.
 * The format string is composed of zero or more directives.
 * @...: argument list
 *
 * Return: int - number of printed letters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count, ok;

	i = 0;
	count = 0;
	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ok = get_print_fun(format[i + 1], args);
			if (ok)
			{
				count += ok;
				i++;
			}
			else
				count += _putchar(format[i]);
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	_putchar(BUF_FLUSH);
	return (count);
}
