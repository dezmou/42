/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:38:39 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:38:40 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_unsigned(t_env *e)
{
	unsigned long value;

	value = get_u_nbr_with_len(e);
	if (e->fl_pos != 0)
		e->fl_pos = 0;
	if (e->fl_pos != 0 || e->fl_space != 0)
		e->fl_space = 0;
	if (e->fl_neg != 0)
		e->fl_zero = ' ';
	TMPS = ft_itoa_u(value);
	apply_precision(e);
	apply_width_dec(e);
	add_str(e, TMPS);
}
