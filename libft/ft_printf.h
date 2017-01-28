/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:50:54 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:50:55 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include <math.h>
# include <string.h>
# include <limits.h>
# include <wchar.h>
# include <locale.h>

# define ARGS e->args
# define STR e->str
# define CHAR e->str[e->char_rendu]
# define NBRC e->char_rendu
# define NBRR e->nbrread
# define PSTR(x) ft_putstr(x)
# define TMPS e->tmpstr
# define SPEC e->specifier
# define LEN e->length
# define VALID "dsSDpDiUoOuUxXcC%"

typedef struct		s_env
{
	int				nbrread;
	va_list			args;
	char			*str;
	int				char_rendu;
	int				list_rendu;
	void			*tab_spec[256];
	char			*tmpstr;
	char			*finalstr;
	char			is_flagged;
	char			fl_neg;
	char			fl_pos;
	char			fl_space;
	char			fl_hash;
	char			fl_zero;
	char			bigx;
	int				width;
	int				finalwidth;
	int				precision;
	int				final_prec;
	char			length;
	char			specifier;
	long			dec_value;
	char			dec_is_neg;
}					t_env;

void				init_env(t_env *e);
void				destroy_env(t_env *e);
int					ft_abs(int n);
int					ft_printf(const char *restrict format, ...);
void				add_char(t_env *e, char c);
void				add_str(t_env *e, char *str);
void				add_wchar(t_env *e, wchar_t c);
void				add_wstr(t_env *e, wchar_t *str);
void				handle_percent(t_env *e);
void				handle(t_env *e);
void				handle_flags(t_env *e);
void				handle_width(t_env *e);
void				handle_precision(t_env *e);
void				handle_length(t_env *e);
void				handle_specifier(t_env *e);
void				get_more_width(t_env *e);
void				get_more_prec(t_env *e);
void				apply(t_env *e);
void				apply_int(t_env *e);
void				apply_str(t_env *e);
void				apply_ptr(t_env *e);
void				apply_char(t_env *e);
void				apply_unsigned(t_env *e);
void				apply_hex_big(t_env *e);
void				apply_hex_short(t_env *e);
void				apply_octal(t_env *e);
void				apply_percent(t_env *e);
void				apply_wstr(t_env *e);
void				apply_hex_zero_octal(t_env *e, char *prefix);
void				apply_width(t_env *e);
void				apply_width_dec(t_env *e);
void				apply_precision(t_env *e);
void				apply_precision_str(t_env *e);
void				apply_width_wstr(t_env *e, wchar_t *str);
void				apply_hex_final(t_env *e);
void				apply_length(t_env *e);
void				apply_wchar(t_env *e);
void				apply_invalid(t_env *e);
void				apply_wstr(t_env *e);
long				get_nbr_with_len(t_env *e);
long				get_u_nbr_with_len(t_env *e);
wchar_t				*ft_cut_wchar(wchar_t *str, int n);

#endif
