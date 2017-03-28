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
NAME                            = zouze
SRCS                            = main.c
SRCSPATH                        = ./srcs/
INCLUDES                        = ./includes
CC                                      = gcc
CFLAGS                          =  -Os
LFLAGS                          = -L srcs/libft/ -lft
SDL2                            = -framework SDL2
SDL2_MIXER                      = -framework SDL2_mixer
SDL2_HEADER             = -I ~/Library/Frameworks/SDL2.framework/Headers
SDL2_HEADER_MIXER       = -I ~/Library/Frameworks/SDL2_mixer.framework/Headers

SDL                             = -F ~/Library/Frameworks $(SDL2_MIXER) $(SDL2)
SDL_HEADER                      = -F ~/Library/Frameworks $(SDL2_HEADER_MIXER)  $(SDL2_HEADER)
INCLUDES_O                      = -I $(INCLUDES) -I ./srcs/libft/
INCLUDES_C                      = $(SDL) $(SDL_HEADER) $(LFLAGS)
SRC                                     = $(addprefix $(SRCSPATH), $(SRCS))
OBJS                            = $(SRC:.c=.o)


all: $(NAME)


$(NAME): $(OBJS)
	make -C ./srcs/libft
	$(CC) -g -o $(NAME) -O3 $(OBJS) $(CFLAGS) $(INCLUDES_C)
%.o: %.c
	$(CC) -o $@ $(INCLUDES_O) $(CFLAGS) $(SDL_HEADER) -c -O0 -flto $<

sdl_install:
		curl https://dl.dropboxusercontent.com/u/22561204/SDL/Archive.zip > /tmp/Archive.zip
		unzip -o /tmp/Archive.zip -d ~/Library/Frameworks/
.PHONY: all clean fclean re
