/*
** EPITECH PROJECT, 2018
** PSU
** File description:
** my_put_err
*/

#include "my.h"

int my_put_stderr(char const *str)
{
	write(2, str, my_strlen(str));
	return (84);
}