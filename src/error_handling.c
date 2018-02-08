/*
** EPITECH PROJECT, 2018
** error_handling
** File description:
** matchstick
*/

#include "my.h"

int send_error(map_t *map, int error)
{
	char *more = "Error: you cannot remove more than";

	switch (error) {
	case OFR:
		my_printf("Error: this line is out of range\n");
		return (OFR);
	case NOT_EN_MATCHES:
		my_printf("Error: you have to remove at least one match\n");
		return (NOT_EN_MATCHES);
	case MORE_MAX:
		my_printf("%s %d matches per turn\n", more, map->max);
		return (MORE_MAX);
	case TOO_MANY:
		my_printf("Error: not enough matches on this line\n");
		return (TOO_MANY);
	default:
		return (TRUE);
	}
}

int str_is_digit(char const *str)
{
	for (int i = 0; str[i]; ++i) {
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
	}
	return (TRUE);
}

int check_line(map_t *map, int line)
{
	if (line == -4096)
		return (INVALID);
	if (line <= 0 || line > map->rows)
		return (OFR);
	return (FALSE);
}

int check_matches(map_t *map, int matches)
{
	if (matches <= 0 || matches > map->max) {
		if (matches == -4096)
			return (INVALID);
		else if (matches <= 0)
			return (NOT_EN_MATCHES);
		else
			return (MORE_MAX);
	} else if (matches > count_matches(map->map[ipt.line - 1])) {
		return (TOO_MANY);
	} else {
		return (FALSE);
	}
}