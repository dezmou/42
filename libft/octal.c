/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:31:29 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:31:30 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_octal(t_env *e)
{
	unsigned long value;

	value = get_u_nbr_with_len(e);
	if (value == 0 && e->precision != 0)
		e->fl_hash = 0;
	TMPS = ft_itoa_base_u(value, 8);
	apply_hex_final(e);
}

void	apply_hex_zero_octal(t_env *e, char *prefix)
{
	if (e->finalwidth >= 1)
		TMPS[0] = prefix[0];
	else
		TMPS = ft_str_join_free("0", TMPS, 2);
}
