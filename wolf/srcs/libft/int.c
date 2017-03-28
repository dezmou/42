/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:29:14 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:29:15 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_int(t_printf_env *e)
{
	long value;

	value = get_nbr_with_len(e);
	if (e->fl_pos != 0)
		e->fl_space = 0;
	if (e->fl_neg != 0)
		e->fl_zero = ' ';
	if (value < 0)
		e->dec_is_neg = 1;
	TMPS = ft_itoa(value);
	apply_precision(e);
	apply_width_dec(e);
	add_str(e, TMPS);
}
