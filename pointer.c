#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
/**
 * print_P - print pointer
 * @c: character
 * @v: argument
 * Return: number of bytes
 */

int print_P(char c, va_list v)
{
	char buff[1024];
	void *ptr = va_arg(v, void *);
	int len;
	(void)c;

	len = sprintf(buff, "%p", ptr);

	write(1, buff, len);
	return (len);

	ptr = malloc(1024);
	free(ptr);
	return (write(1, &ptr, 8));
}
