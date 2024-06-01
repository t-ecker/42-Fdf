# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tecker <tecker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 15:20:52 by tecker            #+#    #+#              #
#    Updated: 2024/06/01 11:30:37 by tecker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_DIR     = ./mlx
MLX         = $(MLX_DIR)/libmlx.a
FRAMEWORKS  = -framework OpenGL -framework AppKit

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = ./src
OBJ_DIR     = ./obj

SRC_basic  	= $(wildcard $(SRC_DIR)/basic/*.c)
SRC_BONUS   = $(wildcard $(SRC_DIR)/bonus/*.c)
SRC_SHARED  = $(wildcard $(SRC_DIR)/shared/*.c)

OBJ_basic  	= $(patsubst $(SRC_DIR)/basic/%.c, $(OBJ_DIR)/%.o, $(SRC_basic))
OBJ_BONUS   = $(patsubst $(SRC_DIR)/bonus/%.c, $(OBJ_DIR)/%.o, $(SRC_BONUS))
OBJ_SHARED  = $(patsubst $(SRC_DIR)/shared/%.c, $(OBJ_DIR)/%.o, $(SRC_SHARED))

NAME        = fdf
NAME_BONUS	= fdf_bonus

all: $(MLX) $(NAME)

bonus: $(MLX) $(NAME_BONUS)

$(NAME): $(OBJ_basic) $(OBJ_SHARED) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(FRAMEWORKS) -o $@ $^ 

$(NAME_BONUS):	$(OBJ_BONUS) $(OBJ_SHARED) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(FRAMEWORKS) -o $@ $^

$(MLX):
	@tar -xvf maps_and_mlx
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/basic/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/shared/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/bonus/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	rm -rf mlx maps
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean bonus fclean re
