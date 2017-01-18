#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"
#include <math.h>
#include <string.h>
#include <limits.h>

# define E t_env *e
# define ARGS e->args
# define STR e->str
# define CHAR e->str[e->char_rendu]
# define NBRC e->char_rendu
# define NBRR e->nbrread
# define PSTR(x) ft_putstr(x)
# define TMPS e->tmpstr
# define SPEC e->specifier

# define TEST "%s %s %s", "this", "is", "a"

# define VALID "dsDpDioOuUxXcCfn%"

//s S p d D i o O u U x X c C
//hh h l ll j z

typedef struct	s_env
{
	int 		nbrread;
	va_list 	args;
	char 		*str;
	int 		char_rendu;
	int 		list_rendu;
	void 		*tab_spec[256];
	char 		*tmpstr;
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
	int 		finalwidth;
	int 		precision;
	int 		final_prec;

	char 		length;
	char 		specifier;
	long		dec_value;

	char 		dec_is_neg;

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

void get_more_width(E);
void get_more_prec(E);

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
void apply_percent(E);
void apply_unsigned_long(E);

void show_params(E);

void apply_width(E);
void apply_width_dec(E);
void apply_precision(E);
void apply_precision_str(E);
void apply_hex_final(E);


void apply_invalid(E);
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
