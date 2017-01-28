/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:11:20 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:11:21 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_length(t_env *e)
{
	if (SPEC == 'c' && LEN == 3)
		SPEC = 'C';
	if (SPEC == 's' && LEN == 3)
		SPEC = 'S';
}

long	get_nbr_with_len(t_env *e)
{
	long value;

	value = va_arg(ARGS, long);
	if (LEN == 3 || LEN == 4 || LEN == 5 || LEN == 7 || SPEC == 'D')
		return (value);
	if (LEN == 1)
		return (char)value;
	if (LEN == 2)
		return (short int)value;
	if (LEN == 6)
		return (size_t)value;
	return (int)(value);
}

long	get_u_nbr_with_len(t_env *e)
{
	unsigned long value;

	value = va_arg(ARGS, unsigned long);
	if (LEN == 3 || LEN == 4 || LEN == 5 || LEN == 7 || SPEC == 'U'
		|| SPEC == 'O')
		return (value);
	if (LEN == 1)
		return (unsigned char)value;
	if (LEN == 2)
		return (unsigned short)value;
	if (LEN == 6)
		return (size_t)value;
	return (unsigned int)(value);
}
