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

NAME = rtmaker

CC = gcc `pkg-config --libs gtk+-3.0`
CFLAGS = -I ./srcs -I ./srcs/libft  `pkg-config --cflags gtk+-3.0`

SRCS = main.c init.c add_obj.c view.c move.c show.c render.c color.c

LIBS = -L ./srcs/libft -lft

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

nolft:
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

test: $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)
	/bin/rm -f $(OBJ)
	./rtmaker
