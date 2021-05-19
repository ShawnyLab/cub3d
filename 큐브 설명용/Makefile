# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 12:03:52 by jinspark          #+#    #+#              #
#    Updated: 2021/05/18 15:30:35 by jinspark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Werror -Wextra -O3
OFLAGS = -c -o
UNAME := $(shell uname)
RMF = rm -rf

SRC_DIR = src
LIB_DIR = lib
LIBFT_DIR = libft
OBJ_DIR := obj
INC_DIR = include

ifeq ($(UNAME),Linux)
	LFLAGS = -lmlx -lft -lXext -lX11 -lm
	MLX_DIR = minilibx-linux
endif
ifeq ($(UNAME),Darwin)
	LFLAGS = -lmlx -lft -framework OpenGL -framework AppKit -lm
	MLX_DIR = minilibx_mms_20200219
	DYN_LIB = libmlx.dylib
endif

_OBJ = cub3d.o image_utils.o save_bitmap.o \
	   parse.o boundary_fill.o initialize.o sprites.o hooks.o \
	   utils.o move_player.o raycast.o quit.o check_args.o \
	   project_walls.o project_walls_utils.o raycast_horizontal.o \
	   raycast_vertical.o parse_utils.o parse_grid.o save_grid.o \
	   parse_resolution.o parse_color.o parse_texture.o
OBJ := $(patsubst %, $(OBJ_DIR)/%, $(_OBJ))

_DEPS = cub3d.h libft.h
DEPS := $(patsubst %, $(INC_DIR)/%, $(_DEPS))

.PHONY: all
all: $(NAME) $(NAME_BONUS)

.PHONY: bonus
bonus: $(NAME_BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) $(OFLAGS) $@ $<

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)/$(MLX_DIR) 2>/dev/null
ifeq ($(UNAME),Darwin)
	cp $(LIB_DIR)/$(MLX_DIR)/$(DYN_LIB) .
endif
	make -C $(LIB_DIR)/$(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I/$(INC_DIR) -L$(LIB_DIR)/$(MLX_DIR) -L$(LIB_DIR)/$(LIBFT_DIR) $(LFLAGS)

$(NAME_BONUS): $(OBJ_BONUS)
	make -C $(LIB_DIR)/$(MLX_DIR) 2>/dev/null
ifeq ($(UNAME),Darwin)
	cp $(LIB_DIR)/$(MLX_DIR)/$(DYN_LIB) .
endif
	make -C $(LIB_DIR)/$(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) -I/$(INC_DIR_BONUS) -L$(LIB_DIR)/$(MLX_DIR) -L$(LIB_DIR)/$(LIBFT_DIR) $(LFLAGS)

.PHONY: clean
clean:
	make -C $(LIB_DIR)/$(LIBFT_DIR) fclean
	make -C $(LIB_DIR)/$(MLX_DIR) clean
	$(RMF) $(OBJ_DIR)
	$(RMF) $(OBJ_DIR_BONUS)
	$(RM) $(wildcard *.bmp)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)
ifeq ($(UNAME),Darwin)
	$(RM) $(DYN_LIB)
endif

.PHONY: re
re: fclean all
