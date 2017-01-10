#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

# define CHARS_HANDLED "sSpdDioOuUxXcC"
# define E t_env *e
# define ARGS e->args
# define STR e->str
# define CHAR e->str[e->char_rendu]
# define NBRC e->char_rendu
# define LRD e->list_rendu

//vu = va_arg(ARGS, int);

typedef struct	s_env
{
	int 		nbrread;
	va_list 	args;
	char 		*str;
	int 		char_rendu;
	int 		list_rendu;
	char 		*str_handled;
}				t_env;

t_env *init_env(void);
void destroy_env(E);


void handle(E);
int ft_printf(const char *restrict format, ...);



#endif
