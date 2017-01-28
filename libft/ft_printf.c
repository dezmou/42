/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 02:58:17 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 02:58:18 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		parse_str(t_env *e)
{
	NBRC += 1;
	if (CHAR == '%')
	{
		handle_percent(e);
		return (1);
	}
	if (STR[NBRC] == 0)
		return (0);
	add_char(e, CHAR);
	return (1);
}

int		ft_printf(const char *restrict format, ...)
{
	t_env e;

	init_env(&e);
	e.str = ft_strdup(format);
	va_start(e.args, format);
	while (parse_str(&e))
		;
	va_end(e.args);
	destroy_env(&e);
	return (e.nbrread);
}
