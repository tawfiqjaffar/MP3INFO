/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include "my.h"

static char *my_malloc(char *s, int n)
{
	char *str = NULL;

	if (n == 1) {
		if (!(str = malloc(sizeof(char) * (MAX_READ + 1))))
			return (NULL);
	} else {
		if (!(str = malloc(sizeof(char) * ((MAX_READ * n) + 1))))
			return (NULL);
		str = my_strcpy(str, s);
		free(s);
	}
	return (str);
}

static char *last_line(int r, int *i, char *line, int fd)
{
	if (r == -1 || fd == -1)
		return (NULL);
	*i = -1;
	if (line != NULL) {
		if (line[0] == 0)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

static char *custom_line(int *i, char *line, int *n, int *j)
{
	*i = *i + 1;
	line[*j] = '\0';
	*n = 1;
	*j = 0;
	return (line);
}

char *get_next_line(const int fd)
{
	static char buff[MAX_READ + 1];
	static char *line;
	static int n = 1;
	static int r = 0;
	static int j = 0;
	static int i = 0;

	buff[MAX_READ] = 0;
	if (i == -1)
		return (NULL);
	if (i == 0) {
		if ((r = read(fd, buff, MAX_READ)) <= 0 || fd < 0)
			return (last_line(r, &i, line, fd));
	}
	if ((line = my_malloc(line, n)) == NULL) {
		return (NULL);
	}
	while (i < r) {
		if (buff[i] == '\0' || buff[i] == '\n')
			return ((custom_line(&i, line, &n, &j)));
		line[j++] = buff[i++];
	}
	i = 0;
	line[j] = 0;
	n++;
	return (get_next_line(fd));
}
