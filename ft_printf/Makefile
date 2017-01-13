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

OBJ = ./libft/*.o ./*.o

$(NAME):
	make re -C ./libft
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	/bin/rm -fv $(OBJ)

fclean: clean
	/bin/rm -fv ./$(NAME)

re: fclean all

test:
	#make re -C ./libft
	gcc $(SRC) -L ./libft -l ft
	./a.out
