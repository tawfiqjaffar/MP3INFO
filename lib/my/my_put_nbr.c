/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Displays any int
*/

#include "my.h"

static int rec_put_nbr(int nb)
{
	if (nb == 0) {
		return (0);
	} else {
		int j = nb % 10;
		char c = j + '0';

		rec_put_nbr(nb / 10);
		my_putchar(c);
		return (1);
	}
}

static int count_digits(int nb)
{
	int count = 0;

	while (nb != 0) {
		nb /= 10;
		count++;
	}
	return (count);
}

int my_put_nbr(int nb)
{
	if (nb == 0) {
		my_putchar('0');
		return (1);
	} else if (nb < 0) {
		my_putchar('-');
		rec_put_nbr(nb * -1);
		return (count_digits(nb) + 1);
	} else {
		rec_put_nbr(nb);
		return (count_digits(nb));
	}
}
