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

SRC	= src/cipher.c \
	  src/cipher_help.c \
	  src/cipher_args.c \
	  src/cipher_encrypt.c \
	  src/cipher_decrypt.c \
	  src/matrix/matrix_create.c \
	  src/matrix/matrix_det.c \
	  src/matrix/matrix_get.c \
	  src/matrix/matrix_from_array.c \
	  src/matrix/matrix_inverse.c \
	  src/matrix/matrix_product.c \
	  src/matrix/matrix_product_elementwise.c \
	  src/matrix/matrix_free.c \
	  src/matrix/matrix_set.c \
	  src/matrix/matrix_set_col.c \
	  src/matrix/matrix_set_row.c \
	  src/matrix/matrix_copy.c \
	  src/matrix/matrix_operations.c \
	  src/matrix/math_dotproduct.c \
	  src/matrix/matrix_broadcasting.c \
	  src/matrix/matrix_identity.c \
	  src/matrix/matrix_scalar.c \

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -lm

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
