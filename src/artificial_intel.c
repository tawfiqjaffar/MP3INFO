/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** artificial intelligence
*/

#include "my.h"

static int abs_val(int n)
{
	return (n < 0 ? n * -1 : n);
}

void get_random_line(map_t *map)
{
	int line = -1;

	do {
		line = random_gen(1, map->rows);
		line = abs_val(line);
	} while (count_matches(map->map[line - 1]) <= 0);
	ipt.line = line;
}

void get_random_matches(map_t *map)
{
	int matches = -1;

	do {
		matches = random_gen(1,
			count_matches(map->map[ipt.line - 1]));
		matches = abs_val(matches);
	} while (matches > map->max);
	if (!matches)
		++matches;
	ipt.matches = matches;
}

void ai_plays(map_t *map)
{
	get_random_line(map);
	get_random_matches(map);
	/* int line = random_gen(1, map->rows);

	line = abs_val(line);
	int matches = random_gen(1, count_matches(map->map[line - 1]));

	matches = abs_val(matches);
	if (matches > map->max)
		matches -= map->max;
	ipt.line = line;
	ipt.matches = matches; */
}