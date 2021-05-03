# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinspark <jinspark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 20:30:32 by jinspark          #+#    #+#              #
#    Updated: 2021/05/03 20:30:41 by jinspark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
FRAMEWORKS	=	-framework OpenGL -framework AppKit

SRCS_PA		=	init.c main.c map_check_one.c map_check_three.c map_check_two.c parse_key.c \
				parse_map.c parse_real.c parse.c
SRCS_RA		=	raycast_fs.c raycast_two.c raycast.c sprite_raycast_two.c sprite_raycast.c \
				x_ray_two.c x_ray.c y_ray_two.c y_ray.c
SRCS_EV		=	check_enemy_two.c check_enemy.c events.c move_two.c move.c player_event_two.c \
				player_event.c save_two.c save.c sprite_collision.c
SRCS_DR		=	dead_screen_two.c draw_dead_screen.c draw_guard.c draw_hud_three.c \
				draw_hud_two.c draw_hud.c draw_sprite_two.c draw_sprite.c draw.c \
				init_cam.c init_mlx_two.c init_mlx.c init_sprite_two.c init_sprite.c \
				draw_two.c draw_level_menu.c

LIB			=	libftprintf.a libmlx.a

OBJS_PA		=	$(SRCS_PA:.c=.o)
OBJS_RA		=	$(SRCS_RA:.c=.o)
OBJS_EV		=	$(SRCS_EV:.c=.o)
OBJS_DR		=	$(SRCS_DR:.c=.o)

PATH_LIB	=	lib/
PATH_DR		=	srcs_drawing/
PATH_EV		=	srcs_events/
PATH_PA		=	srcs_parsing/
PATH_RA		=	srcs_raycasting/

all		: 	$(NAME)

bonus	:	$(NAME)

$(NAME)	:	$(addprefix $(PATH_DR), $(OBJS_DR)) $(addprefix $(PATH_EV), $(OBJS_EV)) \
			$(addprefix $(PATH_PA), $(OBJS_PA)) $(addprefix $(PATH_RA), $(OBJS_RA))
			$(CC) -o $(NAME) $(FLAGS) $(FRAMEWORKS) $(addprefix $(PATH_LIB), $(LIB)) \
			$(addprefix $(PATH_DR), $(OBJS_DR)) $(addprefix $(PATH_EV), $(OBJS_EV)) \
			$(addprefix $(PATH_PA), $(OBJS_PA)) $(addprefix $(PATH_RA), $(OBJS_RA))

clean	:	
				rm -rf $(addprefix $(PATH_DR), $(OBJS_DR)) $(addprefix $(PATH_EV), $(OBJS_EV)) \
				$(addprefix $(PATH_PA), $(OBJS_PA)) $(addprefix $(PATH_RA), $(OBJS_RA))

fclean	:	clean
				rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

#compiling .o with flags
$(PATH_DR)%.o		:	$(PATH_DR)%.c
			$(CC) $(FLAGS) -o $@ -c $<

$(PATH_EV)%.o		:	$(PATH_EV)%.c
			$(CC) $(FLAGS) -o $@ -c $<

$(PATH_PA)%.o		:	$(PATH_PA)%.c
			$(CC) $(FLAGS) -o $@ -c $<

$(PATH_RA)%.o		:	$(PATH_RA)%.c
			$(CC) $(FLAGS) -o $@ -c $<
