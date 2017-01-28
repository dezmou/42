/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:24:09 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:24:10 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_prefix(t_env *e)
{
	char *final;

	if (e->specifier == 'o' || e->specifier == 'O')
	{
		if (e->precision >= (int)ft_strlen(TMPS) && e->precision != 0)
			return (ft_strdup(""));
		return (ft_strdup("0"));
	}
	else
	{
		final = ft_strdup("0x");
		if (SPEC != 'p')
			final[1] = e->bigx;
	}
	return (final);
}

static void		apply_hex_zero(t_env *e, char *prefix)
{
	if (e->specifier == 'o' || e->specifier == 'O')
	{
		apply_hex_zero_octal(e, prefix);
		return ;
	}
	if (e->finalwidth >= 2)
	{
		TMPS[0] = prefix[0];
		TMPS[1] = prefix[1];
	}
	else if (e->finalwidth >= 1)
	{
		TMPS[0] = prefix[1];
		if (e->specifier == 'x')
			TMPS = ft_str_join_free("x", TMPS, 2);
		else
			TMPS = ft_str_join_free("X", TMPS, 2);
	}
	else
	{
		if (e->specifier == 'x' || SPEC == 'p')
			TMPS = ft_str_join_free("0x", TMPS, 2);
		if (SPEC == 'X')
			TMPS = ft_str_join_free("0X", TMPS, 2);
	}
}

void			apply_hex_final(t_env *e)
{
	char *tmp;

	apply_precision(e);
	tmp = get_prefix(e);
	if (e->fl_neg != 0)
		e->fl_zero = ' ';
	if (e->fl_hash != 0 || SPEC == 'p')
	{
		if (e->fl_zero == ' ')
		{
			TMPS = ft_str_join_free(tmp, TMPS, 2);
			apply_width(e);
		}
		else
		{
			get_more_width(e);
			apply_width(e);
			apply_hex_zero(e, tmp);
		}
	}
	else
		apply_width(e);
	add_str(e, TMPS);
	free(tmp);
}

void			apply_hex_big(t_env *e)
{
	unsigned long value;

	value = get_u_nbr_with_len(e);
	if (value == 0)
		e->fl_hash = 0;
	TMPS = ft_itoa_base_u(value, 16);
	e->bigx = 'X';
	apply_hex_final(e);
}

void			apply_hex_short(t_env *e)
{
	unsigned long value;

	value = get_u_nbr_with_len(e);
	if (value == 0)
		e->fl_hash = 0;
	TMPS = ft_itoa_base_u(value, 16);
	ft_strtolower(TMPS);
	e->bigx = 'x';
	apply_hex_final(e);
}
