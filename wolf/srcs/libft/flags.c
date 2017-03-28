/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:05:24 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:05:26 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_flag(t_printf_env *e, char c)
{
	e->is_flagged = 1;
	if (c == '-')
		e->fl_neg = 1;
	if (c == '+')
		e->fl_pos = 1;
	if (c == ' ')
		e->fl_space = 1;
	if (c == '#')
		e->fl_hash = 1;
	if (c == '0')
		e->fl_zero = '0';
	NBRC++;
	handle_flags(e);
}

void		handle_flags(t_printf_env *e)
{
	if (CHAR == '-')
		handle_flag(e, '-');
	if (CHAR == '+')
		handle_flag(e, '+');
	if (CHAR == ' ')
		handle_flag(e, ' ');
	if (CHAR == '#')
		handle_flag(e, '#');
	if (CHAR == '0')
		handle_flag(e, '0');
	if (CHAR == '\'')
		handle_flag(e, '\'');
}
