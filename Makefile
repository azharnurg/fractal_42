# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anurgali <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 00:55:08 by anurgali          #+#    #+#              #
#    Updated: 2019/10/03 17:18:17 by anurgali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= gcc

FLAG	= -Wall -Wextra -Werror
MLX		= -I./minilibx_macos -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

SRCS	= draw.c\
			julia.c\
			mandel.c\
			burningship.c\

OBJ 	= ${SRCS:.c=.o}
INCLUDE = -I fractol.h -L ./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(FLAG) $(INCLUDE) $(MLX) $(OBJ) -o $(NAME)
clean:
				@/bin/rm -f $(OBJ)

fclean: clean
				@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
