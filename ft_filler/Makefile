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

NAME = momartin.filler

CC = gcc
CFLAGS =  -I ./srcs -I ./libft

SRCS = main.c init.c parse_infos.c parse_infos_utils.c set_piece.c \
		engine.c

LIBS = -L ./libft -lft

OBJ = $(addprefix ./srcs/, $(SRCS:.c=.o))

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
