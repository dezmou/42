LIBFT = libft/*.c

all:
	./start.sh
	-gcc -I header main.c misc.c draw/draw.c $(LIBFT)

test: all
	-./a.out
	./end.sh