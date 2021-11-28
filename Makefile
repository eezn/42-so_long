# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jin-lee <jin-lee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 15:39:38 by jin-lee           #+#    #+#              #
#    Updated: 2021/11/29 03:07:23 by jin-lee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

OPTIONS		= -arch x86_64

# -L<library dir> -l<library>
LIB			= -L./mlx -lmlx -framework OpenGL -framework AppKit
LIBFT		= ./libft/libft.a
LIBMLX		= ./mlx/libmlx.a

INCS_DIR	= ./includes
OBJS_DIR	= ./objects

SRCS_DIR	= ./srcs \
			  ./srcs/get_next_line \
			  ./srcs/read_map \
			  ./srcs/draw_images \
			  ./srcs/input_process \
			  ./srcs/utils

SRCS		= ./srcs/main.c \
			  \
			  ./srcs/get_next_line/get_next_line.c \
			  \
			  ./srcs/read_map/malloc_map.c \
			  ./srcs/read_map/map_utils.c \
			  ./srcs/read_map/map_utils2.c \
			  ./srcs/read_map/read_map.c \
			  \
			  ./srcs/draw_images/draw_base.c \
			  ./srcs/draw_images/draw_player.c \
			  ./srcs/draw_images/draw_utils.c \
			  \
			  ./srcs/input_process/key_press.c \
			  ./srcs/input_process/check_movable.c \
			  \
			  ./srcs/utils/exit_error.c \
			  ./srcs/utils/exit_game.c \
			  ./srcs/utils/exit_success.c \
			  ./srcs/utils/print_line.c


OBJS		= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
vpath %.c $(SRCS_DIR)

RM			= rm -f


all: $(NAME)


# so_long
$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	@$(CC) $(LIB) $^ -o $@
	@echo "\033[32m"so_long built successfully."\033[0m"

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(INCS_DIR) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $@


# library
$(LIBFT):
	@$(MAKE) -C ./libft all

# $(LIBMLX):
# 	@$(MAKE) -C ./mlx all

# clean, fclean, re
clean:
	@$(MAKE) -C ./libft clean
#	@$(MAKE) -C ./mlx clean
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@$(MAKE) -C ./libft fclean
#	@$(MAKE) -C ./mlx clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, so_long, clean, fclean, re