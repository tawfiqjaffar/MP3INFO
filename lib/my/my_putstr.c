/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
	return (my_strlen(str));
}
