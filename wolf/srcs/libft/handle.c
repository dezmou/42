/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:06:28 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:06:30 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_spec(t_printf_env *e)
{
	e->is_flagged = 0;
	e->fl_neg = 0;
	e->fl_pos = 0;
	e->fl_space = 0;
	e->fl_hash = 0;
	e->fl_zero = ' ';
	e->width = 0;
	e->precision = -1;
	e->length = 0;
	e->specifier = 0;
	e->bigx = 0;
	e->finalwidth = 0;
	e->dec_is_neg = 0;
}

void	handle_percent(t_printf_env *e)
{
	reset_spec(e);
	NBRC += 1;
	handle(e);
}

void	handle(t_printf_env *e)
{
	handle_flags(e);
	handle_width(e);
	handle_precision(e);
	handle_length(e);
	handle_specifier(e);
	apply(e);
}
