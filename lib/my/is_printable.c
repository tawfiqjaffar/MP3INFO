/*
** EPITECH PROJECT, 2018
** PSU_my_printf
** File description:
** is_printable
*/

#include "my.h"

int is_printable(const char c)
{
	return (c >= 32 && c < 127);
}
