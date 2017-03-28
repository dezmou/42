/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:12:21 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:12:23 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		apply_prec_final(t_printf_env *e)
{
	char *strmore;

	if (e->final_prec > 0)
	{
		strmore = ft_strnew(e->final_prec);
		strmore = ft_memset(strmore, '0', e->final_prec);
		TMPS = ft_str_join_free(strmore, TMPS, 2);
		free(strmore);
	}
	if (e->precision > 0)
		e->fl_zero = ' ';
}

void			apply_precision(t_printf_env *e)
{
	if (e->precision == 0)
		if (TMPS[0] == '0')
			TMPS[0] = 0;
	get_more_prec(e);
	if (TMPS[0] == '-')
	{
		e->final_prec++;
		apply_prec_final(e);
		TMPS[e->final_prec] = '0';
		TMPS[0] = '-';
		e->final_prec--;
	}
	else
		apply_prec_final(e);
}

void			apply_precision_str(t_printf_env *e)
{
	if ((int)ft_strlen(TMPS) > e->precision)
		TMPS[e->precision] = 0;
}

wchar_t			*ft_cut_wchar(wchar_t *str, int n)
{
	int		total;
	int		i;
	wchar_t *strr;

	if (!(strr = malloc(sizeof(wchar_t) * ft_wstr_false_len(str) + 4)))
		return (NULL);
	strr = ft_memcpy(strr, str, sizeof(wchar_t) * ft_wstr_false_len(str) + 4);
	total = 0;
	i = -1;
	while (strr[++i])
	{
		total += ft_wcharlen(strr[i]);
		if (total > n)
		{
			strr[i] = 0;
			return (strr);
		}
	}
	return (strr);
}
