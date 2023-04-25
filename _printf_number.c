#include "main.h"

/**
 * _printf_d - prints a decimal number
 * @n: number to print
 *
 * Return: number of characters printed
 */
int _printf_d(int n)
{
    int len = 0;

    if (n < 0)
    {
        len += _putchar('-');
        n = -n;
    }

    if (n / 10)
        len += _printf_d(n / 10);

    len += _putchar(n % 10 + '0');

    return (len);
}

/**
 * _printf_i - prints an integer
 * @n: number to print
 *
 * Return: number of characters printed
 */
int _printf_i(int n)
{
    return (_printf_d(n));
}
