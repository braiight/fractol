# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 14:16:14 by gumallet          #+#    #+#              #
#    Updated: 2025/01/17 16:49:53 by gumallet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
	init.c \
	exec.c \
	mandelbrot.c \
	mandeloops.c \
	julia_dynamic.c \
	julia_fixed.c \
	julioops.c \
	burning_ship.c \
	shloops.c \
	housekeeping.c

CC = @cc
CFLAGS = -Wall -Werror -Wextra  -g3 -Ilibft -IMLX42/include
NAME = fractol
LDFLAGS = -ldl -lglfw -pthread -lg
LIBFT = -Llibft -lft
LIBMLX = MLX42/build/libmlx42.a

OBJECTS = $(SRCS:.c=.o)

$(NAME): $(OBJECTS)
	@make -C libft
	@cmake MLX42 -B MLX42/build && make -C MLX42/build -j4
	$(CC)  $(OBJECTS) $(LIBMLX) $(LIBFT) $(LDFLAGS) -o $(NAME) $(CFLAGS)
	@echo "\033[1;33m fractol executable created!"

all: $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJECTS)
	@echo 'fractol object files deleted!'

fclean: clean
	make -C libft fclean
	rm -f $(NAME) $(BONUS_NAME)
	@echo 'fractol executable deleted!'

re: fclean $(NAME)

.PHONY: all clean fclean re