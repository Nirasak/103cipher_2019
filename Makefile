##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/print_descr.c	\
		src/cipher.c	\
		src/encryption.c	\
		src/matrix.c	\
		src/my_strisnum.c	\
		src/decryption.c	\
		src/decryption2.c	\
		src/matrix_double.c	\
		src/matrix_double2.c	\
		src/mult_matrix.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	103cipher

CFLAGS	=	-W -Wall -g3

CPPFLAGS	=	-I include/

LDFLAGS	=	-lm

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
