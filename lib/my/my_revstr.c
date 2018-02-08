/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** Reverses a given string and returns it
*/

#include "my.h"

static void swap_chars(char *a, char *b)
{
	char temp = *a;

	*a = *b;
	*b = temp;
}

char *my_revstr(char *str)
{
	int lenstr = my_strlen(str);

	for (int i = 0; i < lenstr / 2; i++)
		swap_chars(&str[i], &str[lenstr - i - 1]);
	return (str);
}
