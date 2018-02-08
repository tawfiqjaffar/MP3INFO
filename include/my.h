/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** function prototypes
*/

#ifndef MY_H_
#define MY_H_

#define TRUE 		1
#define FALSE 		0
#define REG_MY 		8
#define DIR_MY 		4
#define CHR_MY 		2
#define BLK_MY		6
#define FIFO_MY 	1
#define MORE_MAX	3
#define INVALID_IPT	4
#define NOT_EN_MATCHES	5
#define TOO_MANY	6
#define INVALID		7
#define OFR		2
#define LINK_MY		10
#define SOCK_MY 	12
#define EOF_EX		-84
#define OCTAL_MY 	"01234567"
#define MAX_READ	4096

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <stdlib.h>

typedef struct function_pointer {
	char flag;
	int (*fun)(va_list);
} fptr_t;

typedef struct map_s {
	char *top_bot;
	char **map;
	int rows;
	int width;
	int last;
	int max;
	int total_matches;
} map_t;

typedef struct input {
	int line;
	int matches;
} input_t;

extern input_t ipt;

ssize_t write(int fildes, const void *buf, size_t nbyte);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_long(long nb);
int my_put_nbr(int nb);
int is_printable(const char c);
int my_atoi(const char *str);
int my_strlen(char const *str);
char *my_strdup(const char *src);
char *to_upr(char *str);
char *my_revstr(char *str);
char *my_strncpy(char *dest, char *src, size_t len);
char *my_strcpy(char *dest, char *src);
int num(va_list ap);
int string(va_list ap);
int chr(va_list ap);
int non_print_aux(char *str, int count);
int non_print(va_list ap);
int percent(va_list ap);
int hex_l(va_list ap);
char *get_next_line(const int fd);
int hex_u(va_list ap);
int binary(va_list ap);
int oct(va_list ap);
int ptr(va_list ap);
char *convert_base_long(long nb, const char *b);
char *convert_base(int n, const char *b);
int parse_flags(va_list ap, char c);
int my_printf_aux(const char *format, va_list ap);
int my_printf(const char *format, ...);
int my_strcmp(char const *str1, char const *str2);
int my_put_stderr(char const *str);

void destroy_map(map_t *map);
map_t *init_map(int const rows, int const max_match);
int compute_last_row(int const rows);
char *build_top_bot(int const rows);
char *print_match(int const width, int const start, int const row);
char **init_board(int const rows);
int str_is_digit(char const *str);
void print_map(map_t *map);
int get_input(void);
int get_line_matches(map_t *map);
int send_error(map_t *map, int error);
int remove_matches(map_t *map);
int count_matches(char const *str);
int count_all_matches(char **str);
int check_matches(map_t *map, int matches);
int check_line(map_t *map, int line);
void put_status(int player);
int random_gen(int const min, int const max);
void ai_plays(map_t *map);

#endif