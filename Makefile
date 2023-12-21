##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Placeholder
##

NAME   = 103cipher

CC	   = gcc

CFLAGS = -Wall -Wextra -Wno-unused-value -Wno-sign-compare \
	-Wno-unused-parameter -I./include

CSFML = -lcsfml-system -lcsfml-window -lcsfml-network \
			-lcsfml-graphics -lcsfml-audio

CRITERION = -lcriterion

SRC	= cipher.c \

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lm

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
