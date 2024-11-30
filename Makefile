# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 15:20:52 by tecker            #+#    #+#              #
#    Updated: 2024/11/30 01:32:20 by tomecker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fdf
NAME_BONUS	= fdf_bonus

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./MLX42
MLX	= $(MLX_DIR)/build/libmlx42.a
LIBS			=-L/opt/homebrew/lib -L$(LIBFT_DIR) -lft -ldl -lglfw -pthread -lm

CFLAGS = -Wall -Werror -Wextra
CC = cc

SRC		   =	./src/basic/main.c

SRC_BONUS  =	./src/bonus/main_bonus.c \
				./src/bonus/control_bonus.c
				

SRC_SHARED =	./src/shared/utils1.c \
				./src/shared/initialize1.c \
				./src/shared/initialize2.c \
				./src/shared/color.c \
				./src/shared/utils2.c \
				./src/shared/debug.c \
				./src/shared/draw1.c \
				./src/shared/draw2.c \
				./src/shared/overlay.c \
				./src/shared/center.c
				


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
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(LIBFT):	$(LIBFT_DIR)/.git
	@make extra -C $(LIBFT_DIR)

$(LIBFT_DIR)/.git:
	@echo "\033[33mInitializing Libft submodule...\033[0m"
	@git submodule update --init --recursive
	@echo "\033[32mLibft submodule initialized.\033[0m"

$(MLX):	$(MLX_DIR)/.git
	@mkdir -p $(MLX_DIR)/build
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(MLX_DIR)/.git:
	@echo "\033[33mInitializing MLX42 submodule...\033[0m"
	@git submodule update --init --recursive
	@echo "\033[32mMLX submodule initialized.\033[0m"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(NAME_BONUS)
# clear;
# @$(MAKE) loading
# clear;

$(NAME_BONUS):	$(MLX) $(LIBFT) $(OBJ_FILES_BONUS) $(OBJ_FILES_SHARED)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(MLX_DIR)/build

re: fclean all

loading:
	@for i in {1..42}; do \
		printf '%s' "█"; \
		sleep 0.01; \
	done

.PHONY: all clean fclean re loading bonus
