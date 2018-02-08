/*
** EPITECH PROJECT, 2018
** PSU_my_ls_bootstrap
** File description:
** my_strdup: same behavior as strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(const char *src)
{
	char *dest = (char *)malloc(my_strlen(src) + 1);
	int i = 0;

	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
