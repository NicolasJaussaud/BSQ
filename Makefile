##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile project
##

CC		=	gcc

CFLAGS	=	-Wall -Wextra -W

SRC		=	main.c \
			readfile.c \
			lib.c \
			initstruct.c \
			createtab.c

OBJ		=	$(SRC:.c=.o)

NAME	=	bsq

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
