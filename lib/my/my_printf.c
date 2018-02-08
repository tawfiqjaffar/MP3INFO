/*
** EPITECH PROJECT, 2018
** my_printf
** File descsription:
** Same as printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

int my_printf_aux(const char *format, va_list ap)
{
	int count = 0;

	for (int i = 0; i < my_strlen(format); ++i) {
		if (format[i] == '%') {
			count += parse_flags(ap, format[++i]);
		} else {
			my_putchar(format[i]);
			count++;
		}
	}
	return (count);
}

int my_printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);
	va_list ap;

	va_start(ap, format);
	return (my_printf_aux(format, ap));
	va_end(ap);
}
