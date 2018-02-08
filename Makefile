##
## EPITECH PROJECT, 2018
## info_file
## File description:
## Makefile
##

RM	=	rm -f

SRC	=	src/build_board.c	\
		src/map.c		\
		src/get_input.c		\
		src/error_handling.c	\
		src/operations.c	\
		src/computations.c	\
		src/random.c		\
		src/artificial_intel.c	\
		main.c

INC_DIR =	include/

LIB_DIR =	lib/my

CFLAGS	=	-I $(INC_DIR)

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my && gcc -o $(NAME) $(OBJ) -L $(LIB_DIR) -lmy

clean:
	$(RM) $(OBJ) src/$(OBJ)
	$(RM) src/\#*\#
	$(RM) *~;
	$(RM) *.o
	$(RM) src/*~;
	$(RM) \#*\#;
	$(RM) include/*.gch
	make -C lib/my clean

fclean: clean
	$(RM) $(NAME);
	make -C lib/my fclean

re:	fclean all

.PHONY:	all clean fclean re