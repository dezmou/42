/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:23:00 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:23:02 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_char(t_printf_env *e)
{
	char str[2];

	str[0] = (char)va_arg(ARGS, int);
	str[1] = 0;
	TMPS = ft_strdup(str);
	if (str[0] == 0)
	{
		NBRR++;
		e->width--;
	}
	if (str[0] == 0 && e->fl_neg != 0)
		ft_putchar(str[0]);
	apply_width(e);
	add_str(e, TMPS);
	if (str[0] == 0 && e->fl_neg == 0)
		ft_putchar(str[0]);
}
