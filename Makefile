# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 15:20:52 by tecker            #+#    #+#              #
#    Updated: 2024/11/20 22:08:50 by tomecker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MLX_DIR     = ./mlx
# MLX         = $(MLX_DIR)/libmlx.a
# FRAMEWORKS  = -framework OpenGL -framework AppKit

# LIBFT_DIR   = ./libft
# LIBFT       = $(LIBFT_DIR)/libft.a

# CC          = cc
# CFLAGS      = -Wall -Wextra -Werror

# SRC_DIR     = ./src
# OBJ_DIR     = ./obj

# SRC_basic  	= $(wildcard $(SRC_DIR)/basic/*.c)
# SRC_BONUS   = $(wildcard $(SRC_DIR)/bonus/*.c)
# SRC_SHARED  = $(wildcard $(SRC_DIR)/shared/*.c)

# OBJ_basic  	= $(patsubst $(SRC_DIR)/basic/%.c, $(OBJ_DIR)/%.o, $(SRC_basic))
# OBJ_BONUS   = $(patsubst $(SRC_DIR)/bonus/%.c, $(OBJ_DIR)/%.o, $(SRC_BONUS))
# OBJ_SHARED  = $(patsubst $(SRC_DIR)/shared/%.c, $(OBJ_DIR)/%.o, $(SRC_SHARED))

# NAME        = fdf
# NAME_BONUS	= fdf_bonus

# all: $(MLX) $(NAME)

# bonus: $(MLX) $(NAME_BONUS)

# $(NAME): $(OBJ_basic) $(OBJ_SHARED) $(MLX) $(LIBFT)
# 	$(CC) $(CFLAGS) $(FRAMEWORKS) -o $@ $^ 

# $(NAME_BONUS):	$(OBJ_BONUS) $(OBJ_SHARED) $(MLX) $(LIBFT)
# 	$(CC) $(CFLAGS) $(FRAMEWORKS) -o $@ $^

# $(MLX):
# 	@tar -xvf maps_and_mlx
# 	@make -C $(MLX_DIR)

# $(LIBFT):
# 	@make -C $(LIBFT_DIR)

# $(OBJ_DIR):
# 	mkdir $(OBJ_DIR)

# $(OBJ_DIR)/%.o: $(SRC_DIR)/basic/%.c | $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR)/%.o: $(SRC_DIR)/shared/%.c | $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJ_DIR)/%.o: $(SRC_DIR)/bonus/%.c | $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -rf $(OBJ_DIR)
# 	make clean -C $(MLX_DIR)
# 	make clean -C $(LIBFT_DIR)

# fclean: clean
# 	rm -f $(NAME) $(NAME_BONUS)
# 	rm -rf mlx maps
# 	make fclean -C $(LIBFT_DIR)

# re: fclean all

# .PHONY: all clean bonus fclean re

NAME        = fdf
NAME_BONUS	= fdf_bonus

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Werror -Wextra
CC = cc

MLX_DIR     = ./mlx
MLX         = $(MLX_DIR)/libmlx.a
FRAMEWORKS  = -framework OpenGL -framework AppKit

SRC		   =	./src/basic/main.c

SRC_BONUS  =	./src/bonus/control_bonus.c \
				./src/bonus/main_bonus.c

SRC_SHARED =	./src/shared/center.c \
				./src/shared/color.c \
				./src/shared/utils1.c \
				./src/shared/utils2.c \
				./src/shared/initialize1.c \
				./src/shared/initialize2.c \
				./src/shared/draw1.c \
				./src/shared/draw2.c


OBJ_DIR = ./obj
SRC_DIR = ./src

OBJ_FILES			=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_FILES_BONUS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_BONUS))
OBJ_FILES_SHARED	=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_SHARED))

all: $(NAME)
	clear;
	@$(MAKE) loading
	clear;

$(NAME): $(MLX) $(LIBFT) $(OBJ_FILES) $(OBJ_FILES_SHARED)
	$(CC) $(CFLAGS) $(FRAMEWORKS) $^ -o $@

$(LIBFT):	$(LIBFT_DIR)/.git
	@make extra -C $(LIBFT_DIR)

$(LIBFT_DIR)/.git:
	@echo "\033[33mInitializing Libft submodule...\033[0m"
	@git submodule update --init --recursive
	@echo "\033[32mLibft submodule initialized.\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(NAME_BONUS)
	clear;
	@$(MAKE) loading
	clear;

$(NAME_BONUS):	$(MLX) $(LIBFT) $(OBJ_FILES_BONUS) $(OBJ_FILES_SHARED)
	$(CC) $(CFLAGS) $(FRAMEWORKS) $^ -o $@

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

loading:
	@for i in {1..42}; do \
		printf '%s' "█"; \
		sleep 0.01; \
	done

.PHONY: all clean fclean re loading bonus
