/*
** EPITECH PROJECT, 2018
** convert_base
** File description:
** Converts a given integer into a given base
*/

#include "my.h"
#include <stdlib.h>

static void append(char *str, const char c)
{
	str[my_strlen(str)] = c;
	str[my_strlen(str)] = 0;
}

char *convert_base(int n, const char *b)
{
	int base = my_strlen(b);

	if (n == 0) {
		return ("0");
	} else {
		char *result = (char *)malloc(32);

		while (n) {
			append(result, b[n % base]);
			n /= base;
		}
		result[my_strlen(result)] = 0;
		my_revstr(result);
		return (result);
	}
}

char *convert_base_long(long nb, const char *b)
{
	int base = my_strlen(b);

	if (!nb) {
		return ("0");
	} else {
		char *result = (char *)malloc(64);

		while (nb) {
			append(result, b[nb % base]);
			nb /= base;
		}
		result[my_strlen(result)] = 0;
		my_revstr(result);
		return (result);
	}
}
