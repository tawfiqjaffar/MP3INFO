/*
** EPITECH PROJECT, 2018
** matchsitck
** File description:
** computations
*/

#include "my.h"

int count_matches(char const *str)
{
	int count = 0;

	for (int i = 0; str[i]; ++i) {
		if (str[i] == '|')
			++count;
	}
	return (count);
}

int count_all_matches(char **str)
{
	int total = 0;

	for (int i = 0; str[i]; ++i) {
		for (int j = 0; str[i][j]; ++j) {
			if (str[i][j] == '|')
				total++;
		}
	}
	return (total);
}

int compute_last_row(int const rows)
{
	int matches = -1;

	for (int i = 0; i < rows; ++i)
		matches += 2;
	return (matches);
}