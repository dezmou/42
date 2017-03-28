/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:02:00 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:02:01 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_tab(t_printf_env *e)
{
	e->tab_spec['d'] = &apply_int;
	e->tab_spec['s'] = &apply_str;
	e->tab_spec['S'] = &apply_wstr;
	e->tab_spec['p'] = &apply_ptr;
	e->tab_spec['D'] = &apply_int;
	e->tab_spec['i'] = &apply_int;
	e->tab_spec['o'] = &apply_octal;
	e->tab_spec['O'] = &apply_octal;
	e->tab_spec['u'] = &apply_unsigned;
	e->tab_spec['U'] = &apply_unsigned;
	e->tab_spec['x'] = &apply_hex_short;
	e->tab_spec['X'] = &apply_hex_big;
	e->tab_spec['c'] = &apply_char;
	e->tab_spec['C'] = &apply_wchar;
	e->tab_spec['%'] = &apply_percent;
	e->tab_spec['R'] = &apply_invalid;
}

void			init_printf_env(t_printf_env *e)
{
	e->nbrread = 0;
	e->char_rendu = -1;
	init_tab(e);
}

void			destroy_env(t_printf_env *e)
{
	free(STR);
}
