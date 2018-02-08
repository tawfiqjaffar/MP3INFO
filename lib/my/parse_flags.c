/*
** EPITECH PROJECT, 2018
** PSU_my_printf
** File description:
** Parses the flags passed to a printf string
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>

int parse_flags(va_list ap, char flag)
{
	int i = -1;
	fptr_t functions[] = {
		{'c', chr}, {'d', num}, {'s', string},
		{'i', num}, {'x', hex_l}, {'X', hex_u}, {'S', non_print},
		{'o', oct}, {'b', binary}, {'%', percent}, {'p', ptr},
		{0, NULL}
	};

	while (functions[++i].flag != flag && functions[i].flag);
	if (functions[i].flag) {
		return (functions[i].fun(ap));
	} else {
		my_putchar('%');
		my_putchar(flag);
		return (2);
	}
}
