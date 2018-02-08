/*
** EPITECH PROJECT, 2018
** operations
** File description:
** matchstick
*/

#include "my.h"

int remove_matches(map_t *map)
{
	int matches = ipt.matches;

	for (int i = map->width; i > 0 && matches > 0; --i) {
		if (map->map[ipt.line - 1][i] == '|') {
			map->map[ipt.line - 1][i] = ' ';
			matches--;
			map->total_matches--;
		}
	}
	return (TRUE);
}