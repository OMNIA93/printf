#include "main.h"

/**
 * get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * 
 * func_arr[] to find a match between the specifier passed to _printf
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
	};
	int flags = 14;

	register int i = 0;

	while (i < flags && func_arr[i].c != s)
	{
		i++;
	}

	if (i < flags)
	{
		return (func_arr[i].f);
	}
	else
	{
		return (NULL);
	}
}



/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 *
 * Return: result string
 */

char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	while (num != 0)
	{
		*--ptr = rep[num % base];
		num /= base;
	}

	return (ptr);
}


/**
 * print_string - loops through a string and prints
 * every character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_string(va_list l, flags_t *f)
{
    char *s = va_arg(l, char *);
    int count = 0;
    (void)f;

    if (!s)
        s = "(null)";
    while (*s != '\0')
    {
        _putchar(*s);
        count++;
        s++;
    }
    return (count);
}

/**
 * print_char - prints a character
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_char(va_list l, flags_t *f)
{
    (void)f;
    _putchar(va_arg(l, int));
    return (1);
}
