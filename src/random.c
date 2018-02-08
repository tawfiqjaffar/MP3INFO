/*
** EPITECH PROJECT, 2018
** random
** File description:
** random
*/

#include "my.h"

int random_gen(int const min, int const max)
{
	return (rand() % max + 1);
}