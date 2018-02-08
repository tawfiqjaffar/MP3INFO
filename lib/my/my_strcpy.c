/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strncpy(char *dest, char *src, size_t len)
{
	int i = 0;

	while (i < len) {
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}

char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i]) {
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}
