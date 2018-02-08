/*
** EPITECH PROJECT, 2018
** PSU_my_printf
** File description:
** basic functions for display
*/

#include "my.h"
#include <stdlib.h>
#include <stdarg.h>

int num(va_list ap)
{
	return (my_put_nbr(va_arg(ap, int)));
}

int string(va_list ap)
{
	return (my_putstr(va_arg(ap, char *)));
}

int chr(va_list ap)
{
	my_putchar(va_arg(ap, int));
	return (1);
}

int non_print_aux(char *str, int count)
{
	for (int i = 0; str[i]; ++i) {
		if (!is_printable(str[i])) {
			char *convert = convert_base(str[i], "01234567");
			int j = 3 - my_strlen(convert);

			my_putchar('\\');
			while (j--)
				my_putchar('0');
			my_putstr(convert);
			count += 4;
		} else {
			my_putchar(str[i]);
			count++;
		}
	}
	return (count);
}

int non_print(va_list ap)
{
	char *str = va_arg(ap, char *);

	return (non_print_aux(str, 0));
}
