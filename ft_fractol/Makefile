# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 20:44:24 by momartin          #+#    #+#              #
#    Updated: 2017/01/06 20:44:26 by momartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./ -I ./libft
SRCS = init.c inaction.c main.c image.c color.c ship.c mandelbrot.c julia.c
LIBS = -lmlx  -L ./libft -lft -framework OpenGL -framework AppKit

OBJ = $(addprefix ./, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(OBJ) -o $(NAME) $(LIBS)
clean:
	make -C ./libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)
re: fclean all

nolft:
	$(CC) $(OBJ) -o $(NAME) $(LIBS)
