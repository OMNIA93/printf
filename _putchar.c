#include <stdio.h>
#include <unistd.h>

/**
 * _putchar - write
 * @c: character
 * Return: zero
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
