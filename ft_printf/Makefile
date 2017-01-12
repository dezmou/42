NAME = libftprintf.a
SRC = ft_printf.c handle.c init.c show.c flags.c

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
	gcc  $(SRC) -L ./libft -lft
	./a.out
