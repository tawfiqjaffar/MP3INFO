/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** Same as atoi
*/

#include "my.h"

static int make_number(const char *str)
{
	int negative = 1;
	int i = 0;
	int result = 0;

	if (str[0] == '-') {
		negative *= -1;
		i++;
	}
	while (str[i] != 0) {
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (negative < 0 ? result * negative : result);
}

int my_atoi(const char *str)
{
	return (make_number(str));
}
