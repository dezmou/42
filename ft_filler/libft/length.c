/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:07:44 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:07:46 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_length(t_printf_env *e)
{
	if (CHAR == 'h')
	{
		e->length = 2;
		if (STR[NBRC + 1] == 'h')
			e->length = 1;
	}
	if (CHAR == 'l')
	{
		e->length = 3;
		if (STR[NBRC + 1] == 'l')
			e->length = 4;
	}
	if (CHAR == 'L')
		e->length = 5;
	if (CHAR == 'z')
		e->length = 6;
	if (CHAR == 'j')
		e->length = 7;
	if (CHAR == 't')
		e->length = 8;
	if (e->length == 1 || e->length == 4)
		NBRC += 2;
	else if (e->length != 0)
		NBRC++;
}
