/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:09:34 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:09:35 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_more_prec(t_env *e)
{
	int more;

	more = e->precision - ft_strlen(TMPS);
	e->final_prec = more;
}

void	get_more_width(t_env *e)
{
	int more;

	more = e->width - ft_strlen(TMPS);
	e->finalwidth = more;
}

void	handle_width(t_env *e)
{
	int		i;
	char	u_width[64];

	i = 0;
	u_width[0] = 0;
	if (CHAR == '*')
	{
		e->width = va_arg(ARGS, int);
		if (e->width < 0)
			e->fl_neg = 1;
		e->width = ft_abs(e->width);
		NBRC++;
		return ;
	}
	while (ft_isdigit(CHAR))
	{
		u_width[i] = CHAR;
		NBRC++;
		i++;
		u_width[i] = '\0';
	}
	e->width = ft_atoi(u_width);
}
