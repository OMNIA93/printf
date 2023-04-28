#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
/**
 * struct specifiers - struct specifiers
 * @c: charachter
 * @i: integer
 * @p: pointer to function
 */
typedef struct specifiers
{
	char *c;
	int i;
	int (*p)(char c, va_list v);
} spec;
int _printf(const char *format, ...);
int istring(char, va_list v);
int fun(va_list, const char*, int);
int _putchar(char c);
int print_int(char c, va_list v);
int binary(char c, va_list v);
int print_oct(char c, va_list v);
int print_unsign(char c, va_list v);
int print_hexa(char c, va_list v);
void hexa(char c);
int print_string(char c, va_list v);
int print_P(char c, va_list v);
int flag(const char *format, int i, va_list v);
int space(const char *format, int i, va_list v);
int hash(const char *format, int i, va_list v);
int plus(const char *format, int i, va_list v);
int print_l(const char *format, int i, va_list v);
int print_Hexa(char c, va_list v);
long int get_number(char c, va_list v);
long int get_min(char c);
int rot(char c, va_list v);
int print_rev(char c, va_list v);
#endif
