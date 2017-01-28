/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:14:41 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:14:42 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_width_dec_pos(t_env *e)
{
	char c;
	char str[2];

	c = ' ';
	if (e->fl_pos == 1)
		c = '+';
	str[0] = c;
	str[1] = 0;
	apply_width(e);
	if (e->finalwidth >= 1)
		TMPS[0] = c;
	else
		TMPS = ft_str_join_free(str, TMPS, 2);
}

void	apply_width_dec(t_env *e)
{
	if (e->fl_zero != ' ')
	{
		if (TMPS[0] != '-' && (e->fl_pos == 1 || e->fl_space == 1))
			apply_width_dec_pos(e);
		else if (TMPS[0] == '-')
		{
			apply_width(e);
			TMPS[e->finalwidth] = e->fl_zero;
			TMPS[0] = '-';
		}
		else
			apply_width(e);
	}
	else
	{
		if (TMPS[0] != '-' && e->fl_pos == 1 && e->fl_space == 0)
			TMPS = ft_str_join_free("+", TMPS, 2);
		if (TMPS[0] != '-' && e->fl_pos != 1 && e->fl_space == 1)
			TMPS = ft_str_join_free(" ", TMPS, 2);
		apply_width(e);
	}
}

void	apply_width(t_env *e)
{
	char *strmore;

	if (e->fl_zero == '0' && e->fl_neg != 0)
		e->fl_zero = ' ';
	get_more_width(e);
	if (e->finalwidth > 0)
	{
		strmore = ft_strnew(e->finalwidth);
		strmore = ft_memset(strmore, e->fl_zero, e->finalwidth);
		if (e->fl_neg == 0)
			TMPS = ft_str_join_free(strmore, TMPS, 2);
		else
			TMPS = ft_str_join_free(TMPS, strmore, 1);
		free(strmore);
	}
}
