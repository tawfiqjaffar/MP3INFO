/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** map
*/

#include "my.h"

void destroy_map(map_t *map)
{
	if (map->top_bot != NULL)
		free(map->top_bot);
	for (int i = 0; map->map[i]; ++i)
		free(map->map[i]);
	if (map->map != NULL)
		free(map->map);
	if (map != NULL)
		free(map);
}

map_t *init_map(int const rows, int const max_match)
{
	map_t *result = NULL;

	if (!(result = malloc(sizeof(map_t))))
		return (NULL);
	result->top_bot = NULL;
	if (!(result->top_bot = build_top_bot(rows)))
		return (NULL);
	result->last = compute_last_row(rows);
	result->width = result->last + 2;
	result->map = NULL;
	if (!(result->map = init_board(rows)))
		return (NULL);
	result->max = max_match;
	result->rows = rows;
	result->total_matches = count_all_matches(result->map);
	return (result);
}

void print_map(map_t *map)
{
	my_printf("%s\n", map->top_bot);
	for (int i = 0; map->map[i]; ++i)
		my_printf("%s\n", map->map[i]);
	my_printf("%s\n", map->top_bot);
}