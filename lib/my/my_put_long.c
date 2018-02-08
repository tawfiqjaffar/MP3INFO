/*
** EPITECH PROJECT, 2018
** PSU_my_printf
** File description:
** my_put_long
*/

#include "my.h"

static int rec_put_long(long nb)
{
	if (nb == 0) {
		return (0);
	} else {
		long j = nb % 10;
		char c = j + '0';

		rec_put_long(nb / 10);
		my_putchar(c);
		return (1);
	}
}

static int count_digits_long(long nb)
{
	int count = 0;

	while (nb) {
		nb /= 10;
		count++;
	}
	return (count);
}

int my_put_long(long nb)
{
	if (nb == 0) {
		my_putchar('0');
		return (1);
	} else if (nb < 0) {
		my_putchar('-');
		rec_put_long(nb * -1);
		return (count_digits_long(nb) + 1);
	} else {
		rec_put_long(nb);
		return (count_digits_long(nb));
	}
}
