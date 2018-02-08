##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compiles library, moves into correct location
##

SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):
	gcc -c $(SRC) -I../../include
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~;
	rm -f \#*\#;

fclean: clean
	rm -f $(NAME); \

re: fclean all
