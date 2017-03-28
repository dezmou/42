/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:10:33 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:10:35 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_invalid(t_printf_env *e)
{
	TMPS = ft_strdup("");
	TMPS[0] = e->specifier;
	apply_width(e);
	add_str(e, TMPS);
}
