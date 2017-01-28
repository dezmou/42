/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:34:04 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:34:07 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_str(t_env *e)
{
	char *str;

	str = (char*)va_arg(ARGS, char*);
	if (str == NULL)
	{
		TMPS = ft_strdup("(null)");
	}
	else
		TMPS = ft_strdup(str);
	apply_precision_str(e);
	apply_width(e);
	add_str(e, TMPS);
}
