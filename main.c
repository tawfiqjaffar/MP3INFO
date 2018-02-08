/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** main
*/

#include "my.h"

static int put_usage(void)
{
	my_printf("USAGE: ./matchstick lines max_matches [-h]\n");
	return (84);
}

static int valid_nb_args(int ac, char **av)
{
	if (ac == 3) {
		if (!str_is_digit(av[1]) || !str_is_digit(av[2])) {
			my_printf("./matchstick: Invalid arguments\n");
			return (FALSE);
		}
		return (TRUE);
	} else if (ac == 2 && my_strcmp(av[1], "-h")) {
		put_usage();
		return (FALSE);
	} else {
		put_usage();
		return (FALSE);
	}
}

static void check_winner(int player)
{
	if (player)
		my_printf("I lost... snif... but I'll get you next time!!\n");
	else
		my_printf("You lost, too bad...\n");
}

static int gameloop(map_t *map, int player, int temp_input)
{
	while (map->total_matches) {
		if (player) {
			do {
				temp_input = get_line_matches(map);
				if (temp_input == EOF_EX)
					return (84);
			} while (temp_input);
		} else {
			ai_plays(map);
		}
		remove_matches(map);
		put_status(player);
		print_map(map);
		player = !player;
	}
	return (player);
}

int main(int ac, char **av)
{
	if (!valid_nb_args(ac, av))
		return (84);
	map_t *map = init_map(my_atoi(av[1]), my_atoi(av[2]));

	if (!map)
		return (my_put_stderr("Malloc failed. Exiting\n"));
	print_map(map);
	int player = 1;
	int temp_input = 1;

	player = gameloop(map, player, temp_input);
	destroy_map(map);
	if (player == 84)
		return (0);
	check_winner(player);
	return (0);
}