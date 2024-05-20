# Variables
MLX_DIR     = ./mlx
MLX         = $(MLX_DIR)/libmlx.a
FRAMEWORKS  = -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Compiler and flags
CC          = cc
# CFLAGS      = -Wall -Wextra -Werror
LDFLAGS     = $(MLX) $(FRAMEWORKS)

# Source files
SRC         = test.c
OBJ         = $(SRC:.c=.o)

# NAME executable
NAME		= fdf

# Build rules
all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBFT)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

# Phony NAMEs
.PHONY: all clean
