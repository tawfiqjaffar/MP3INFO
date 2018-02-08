/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** get_input
*/

#include "my.h"
#include <stdio.h>

input_t ipt;

int get_input(void)
{
	char *buf = get_next_line(0);

	if (!buf) {
		return (EOF_EX);
	} else if (!str_is_digit(buf)) {
		free(buf);
		my_printf("Error: invalid input (positive number expected)\n");
		return (-4096);
	}
	int i = my_atoi(buf);

	free(buf);
	return (i);
}

static int get_modal(map_t *map, int mode)
{
	int input = 0;

	if (mode == 0)
		my_printf("Line: ");
	else
		my_printf("Matches: ");
	input = get_input();
	if (input == EOF_EX)
		return (EOF_EX);
	return (input);
}

int get_line_matches(map_t *map)
{
	int line = get_modal(map, 0);

	if (line == EOF_EX)
		return (EOF_EX);
	int check = check_line(map, line);

	if (check)
		return (send_error(map, check));
	ipt.line = line;
	int matches = get_modal(map, 1);

	if (matches == EOF_EX)
		return (EOF_EX);
	check = check_matches(map, matches);
	if (check)
		return (send_error(map, check));
	ipt.matches = matches;
	return (FALSE);
}

void put_status(int player)
{
	if (player)
		my_printf("Player removed %d match(es) from line %d\n",
			ipt.matches, ipt.line);
	else
		my_printf("AI removed %d match(es) from line %d\n",
			ipt.matches, ipt.line);
}
