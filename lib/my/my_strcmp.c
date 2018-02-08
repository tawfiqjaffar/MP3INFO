/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *str1, char const *str2)
{
	for (int i = 0; str1[i]; ++i) {
		if (str1[i] != str2[i])
			return (FALSE);
	}
	return (TRUE);
}
