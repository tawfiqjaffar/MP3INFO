/*
** EPITECH PROJECT, 2018
** to_upper
** File description:
** to_upper
*/

#include "my.h"

char *to_upr(char *str)
{
	char *copy = my_strdup(str);

	for (int i = 0; copy[i]; ++i) {
		if (copy[i] >= 'A' && copy[i] <= 'Z')
			copy[i] += 32;
	}
	return (copy);
}
