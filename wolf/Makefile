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

NAME = wolf3d

CC = gcc -Wall -Wextra -Werror -o2 -flto

CFLAGS = -I ./srcs -I ./srcs/libft -flto

SRCS = main.c init.c image.c color.c player.c key.c refresh.c wall.c ray.c \
		real_view.c load_image.c wall_utils.c

LIBS = -L ./srcs/libft -lft  -lmlx -framework OpenGL -framework AppKit

OBJ = $(addprefix ./srcs/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./srcs/libft
	$(CC) $(OBJ) -o $(NAME) $(LIBS)
clean:
	make -C ./srcs/libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C ./srcs/libft fclean
	/bin/rm -f $(NAME)
re: fclean all

#nolft: $(OBJ)
#	$(CC) $(OBJ) -o $(NAME) $(LIBS)

#test: nolft
#	./wolf3d
