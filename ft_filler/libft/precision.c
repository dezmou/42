/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:08:18 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:08:21 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_precision(t_printf_env *e)
{
	int		i;
	char	u_width[64];

	i = 0;
	if (CHAR == '.')
	{
		e->precision = 0;
		NBRC++;
		if (CHAR == '*')
			e->precision = va_arg(ARGS, int);
		else
			while (ft_isdigit(CHAR))
			{
				u_width[i] = CHAR;
				NBRC++;
				i++;
				u_width[i] = '\0';
			}
		if (i)
			e->precision = ft_atoi(u_width);
	}
}
