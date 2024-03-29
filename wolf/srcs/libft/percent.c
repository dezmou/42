/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:32:12 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:32:13 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_percent(t_printf_env *e)
{
	TMPS = ft_strdup("%");
	apply_width(e);
	add_str(e, TMPS);
}
