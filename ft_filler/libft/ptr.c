/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:33:18 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:33:19 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_ptr(t_printf_env *e)
{
	long value;

	value = (long)va_arg(ARGS, void*);
	if (value == 0 || (void*)value == NULL)
	{
		TMPS = ft_strdup("0");
		apply_hex_final(e);
		return ;
	}
	TMPS = ft_itoa_base_u(value, 16);
	ft_strtolower(TMPS);
	apply_hex_final(e);
}
