/*
** EPITECH PROJECT, 2018
** PSU_my_printf
** File description:
** Functions for base flags
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

int hex_u(va_list ap)
{
	return (my_putstr(convert_base(va_arg(ap, int), "0123456789ABCDEF")));
}

int hex_l(va_list ap)
{
	return (my_putstr(convert_base(va_arg(ap, int), "0123456789abcdef")));
}

int oct(va_list ap)
{
	return (my_putstr(convert_base(va_arg(ap, int), "01234567")));
}

int binary(va_list ap)
{
	return (my_putstr(convert_base(va_arg(ap, int), "01")));
}

int ptr(va_list ap)
{
	long addr = va_arg(ap, long);

	my_putstr("0x");
	return (my_putstr(convert_base_long(addr, "0123456789abcdef")) + 2);
}
