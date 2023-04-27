#ifndef MAIN _H
#define MAIN_H

#include <stdarg.h>

/**
 * struct print_fmt - struct containing a print format and a function pointer
 * @format: the format specifier
 * @printer: the function that handles the format specifier
 *
 * Description: This struct associates a printf format specifier with the
 * function that handles it.
 */
typedef struct print_fmt
{
	char *format;
	int (*printer)(va_list);
} print_fmt_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_pointer(va_list args);
int print_rev(va_list args);
int _putchar(char c);
int _puts(char *str);

#endif
