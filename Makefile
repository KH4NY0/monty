CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89
SRC = main.c monty_utils.c opcodes1.c opcodes2.c
OBJ = $(SRC:.c=.o)
NAME = monty

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c monty.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: fclean all

.PHONY: all clean oclean fclean re
