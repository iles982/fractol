# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 02:27:48 by tclarita          #+#    #+#              #
#    Updated: 2019/11/16 10:16:13 by tclarita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c julia.c key.c mandelbrot.c trash.c mandelbar.c burning_ship.c

HEADER = fractol.h

FLAGS = -Wall -Werror -Wextra

FRAMEWORKS = -framework OpenGL -framework AppKit
PTHREAD = -lpthread
LIBFT = libft
MLX = minilibx_macos
LIBA = libft/libft.a
MLXLIBA = minilibx_macos/libmlx.a
COLOR = \033[2;14m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIBFT) -silent
	@make -C $(MLX) -silent
	@clang -o $(NAME) $(FLAGS) $(SRC) $(LIBA) $(MLXLIBA) $(FRAMEWORKS) $(PTHREAD)
	@echo "$(COLOR)Project successfully compiled"

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(MLX)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
