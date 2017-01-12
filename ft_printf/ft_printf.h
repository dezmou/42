#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

# define E t_env *e
# define ARGS e->args
# define STR e->str
# define CHAR e->str[e->char_rendu]
# define NBRC e->char_rendu
# define LRD e->list_rendu
# define NBRR e->nbrread
# define PSTR(x) ft_putstr(x)

# define TEST "-->bonjour"

//vu = va_arg(ARGS, int);

/* rendu
0 = %
1 = flags
2 = width
3 = .precision
4 = length
5 = specifier
*/



typedef struct	s_env
{
	int 		nbrread;
	va_list 	args;
	char 		*str;
	int 		char_rendu;
	int 		list_rendu;
	char 		*str_handled;

	char 		fl_neg;
	char 		fl_pos;
	char 		fl_space;
	char 		fl_hash;
	char 		fl_zero;

}				t_env;

t_env *init_env(void);
void destroy_env(E);


void handle(E);
int ft_printf(const char *restrict format, ...);
void add_char(E,char c);
void handle_percent(E);
void add_str(E,char *str);
void handle_flags(E);
#endif
