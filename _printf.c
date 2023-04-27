#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0, count = 0;
	char *str;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;

			switch (format[i])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char *);
					if (str)
					{
						count += _puts(str);
						break;
					}
					count += _puts("(null)");
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
