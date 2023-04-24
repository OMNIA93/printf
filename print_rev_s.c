#include "main.h"
/**
 * print_rev_s - print string in reverse order
 *
 * @arg: string to be printed
 * Return: int - number of character printed
 */
int print_rev_s(va_list arg)
{
	char *s;
	int i, len;

	i = 0;
	s = va_arg(arg, char *);
	if (s == NULL)
		s = "(null)";

	while (s[i])
		i++;

	len = i;
	for (i = i - 1; i >= 0; i--)
		_putchar(s[i]);

	return (len);
}
