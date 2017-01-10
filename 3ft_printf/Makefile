NAME = libftprintf.a

SRCS = ft_printf.c \
		init.c\
		handle.c

OBJ = $(SRC:.c=.o)


$(NAME): $(OBJ)
	gcc -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)



all: $(NAME)
