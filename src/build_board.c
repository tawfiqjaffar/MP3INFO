/*
** EPITECH PROJECT, 2018
** matchsitck
** File description:
** build_board
*/

#include "my.h"

char *build_top_bot(int const rows)
{
	int width = compute_last_row(rows) + 2;
	char *border = NULL;

	if (!(border = malloc(sizeof(char) * width + 1)))
		return (NULL);
	for (int i = 0; i < width; ++i)
		border[i] = '*';
	border[width] = 0;
	return (border);
}

static void fill_matches(char *row, int amount, int *index)
{
	int i = *index;

	while (*index < amount + i) {
		row[*index] = '|';
		(*index)++;
	}
	(*index)--;
}

static char *init_line(int const width, int const start, int const row)
{
	char *result = NULL;

	if (!(result = malloc(sizeof(char) * width + 1)))
		return (NULL);
	int amount = compute_last_row(row);

	for (int i = 0; i < width; ++i) {
		if (i == 0 || i == width - 1) {
			result[i] = '*';
		} else {
			if (i != start)
				result[i] = ' ';
			else
				fill_matches(result, amount, &i);
		}
	}
	result[width] = 0;
	return (result);
}

char **init_board(int const rows)
{
	int last = compute_last_row(rows);
	int mid = (last + 2) / 2;
	char **result = NULL;

	if (!(result = malloc(sizeof(char *) * rows + 1)))
		return (NULL);
	for (int i = 0; i < rows; ++i) {
		result[i] = init_line(last + 2, mid, i + 1);
		if (!result[i])
			return (NULL);
		--mid;
	}
	result[rows] = NULL;
	return (result);
}