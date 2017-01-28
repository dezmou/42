/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:15:45 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:15:46 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		assign(t_printf_env *e, void (*func)(t_printf_env*))
{
	func(e);
}

static int		is_valid_spec(t_printf_env *e)
{
	char	*valid;
	int		i;

	if (e->specifier <= 0)
		return (0);
	i = -1;
	valid = ft_strdup(VALID);
	while (valid[++i])
	{
		if (valid[i] == e->specifier)
		{
			free(valid);
			return (1);
		}
	}
	free(valid);
	return (0);
}

void			apply(t_printf_env *e)
{
	apply_length(e);
	if (is_valid_spec(e))
		assign(e, e->tab_spec[(int)e->specifier]);
	else
		assign(e, e->tab_spec['R']);
}
