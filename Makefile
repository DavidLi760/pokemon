NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -Imlx -g3
LFLAGS  = -Lmlx -lmlx -lX11 -lXext -lXrandr -lm
SRC     =	main.c\
			parsing.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

MLX:
	make -C mlx

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	rm -rf $(OBJ)

.PHONY: all clean fclean re
