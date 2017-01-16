#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <math.h>

# define E t_env *e
# define ARGS e->args
# define STR e->str
# define CHAR e->str[e->char_rendu]
# define NBRC e->char_rendu
# define NBRR e->nbrread
# define PSTR(x) ft_putstr(x)
# define TEST "hello %f ", 654.45

//s S p d D i o O u U x X c C
//hh h l ll j z

typedef struct	s_env
{
	int 		nbrread;
	va_list 	args;
	char 		*str;
	int 		char_rendu;
	int 		list_rendu;
	char 		u_width[256];
	void 		*tab_spec[256];
/*#####ALL INFOS ABOUT %VAR ######*/

	char 		*finalstr;
	char 		is_flagged;
	char 		fl_neg;
	char 		fl_pos;
	char 		fl_space;
	char 		fl_hash;
	char 		fl_zero;
	char 		bigx;


	int 		width;
	int 		precision;

	char 		length;
	char 		specifier;


}				t_env;

void init_env(E);
void destroy_env(E);


int ft_printf(const char *restrict format, ...);
void add_char(E,char c);
void add_str(E,char *str);

void handle_percent(E);
void handle(E);
void handle_flags(E);
void handle_width(E);
void handle_precision(E);
void handle_length(E);
void handle_specifier(E);

void apply(E);
void apply_int(E);
void apply_str(E);
void apply_ptr(E);
void apply_long(E);
void apply_char(E);
void apply_unsigned(E);
void apply_hex_big(E);
void apply_hex_short(E);
void apply_octal(E);
void apply_float(E);
#endif


/*
length:
1 : hh
2 : h
3 : l
4 : ll
5: L
6 : z
7 : j
8 ; t
*/
