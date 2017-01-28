# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: momartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 04:24:16 by momartin          #+#    #+#              #
#    Updated: 2017/01/23 04:24:18 by momartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c\
		init.c \
		show.c \
		handle/flags.c \
		handle/width.c \
		handle/precision.c \
		handle/length.c \
		handle/specifier.c \
		handle/handle.c \
		apply/apply.c \
		apply/int.c \
		apply/str.c \
		apply/ptr.c \
		apply/char.c \
		apply/unsigned.c \
		apply/hexa.c \
		apply/octal.c \
		apply/percent.c \
		apply/apply_width.c \
		apply/apply_precision.c \
		apply/apply_invalid.c \
		apply/apply_length.c \
		apply/unicode.c


OBJ = 	$(addprefix libft/, ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o \
		ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstlen.o\
		ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o \
		ft_lstaddend.o ft_putwchar.o  \
		ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o \
		ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memcpy_bck.o \
		ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o \
		ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o \
		ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o \
		ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o \
		ft_strtolower.o  ft_itoa_u.o ft_itoa_base_u.o \
		ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o \
		ft_striteri.o ft_strjoin.o ft_strjoin.o ft_strlcat.o \
		ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o \
		ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o \
		ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o \
		ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o \
		ft_range.o ft_new_matrix.o ft_del_matrix.o ft_cpy_matrix.o \
		ft_set_mat_elem.o ft_get_mat_elem.o ft_transpose_mat.o \
		ft_sum_mat.o ft_mult_mat.o ft_itoa_base.o)

OBJ += ft_printf.o\
		init.o \
		show.o \
		flags.o \
		width.o \
		precision.o \
		length.o \
		specifier.o \
		handle.o \
		apply.o \
		int.o \
		str.o \
		ptr.o \
		char.o \
		unsigned.o \
		hexa.o \
		octal.o \
		percent.o \
		apply_width.o \
		apply_precision.o \
		apply_invalid.o \
		apply_length.o \
		unicode.o


$(NAME):
	make re -C ./libft
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	make clean -C ./libft
	/bin/rm -fv $(OBJ)

fclean: clean
	make fclean -C ./libft
	/bin/rm -fv ./$(NAME)

re: fclean all
