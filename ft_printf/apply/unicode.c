/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:35:00 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:35:01 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	apply_width_wstr(t_env *e, wchar_t *str)
{
	int len;

	len = ft_wstrlen(str);
	if (e->width != 0)
		if (len < e->width)
		{
			TMPS = ft_strnew(e->width - len);
			TMPS = ft_memset(TMPS, ' ', e->width - len);
			if (e->fl_zero != ' ' && e->fl_neg == 0)
				TMPS = ft_memset(TMPS, '0', e->width - len);
			if (e->fl_neg == 0)
			{
				add_str(e, TMPS);
				add_wstr(e, str);
			}
			else
			{
				add_wstr(e, str);
				add_str(e, TMPS);
			}
			return ;
		}
	add_wstr(e, str);
}

void	apply_wstr(t_env *e)
{
	wchar_t		*str;
	int			i;

	i = -1;
	str = (wchar_t*)va_arg(ARGS, wchar_t*);
	if (str == NULL)
	{
		TMPS = ft_strdup("(null)");
		apply_width(e);
		add_str(e, TMPS);
		return ;
	}
	if (e->precision != -1)
	{
		str = ft_cut_wchar(str, e->precision);
	}
	apply_width_wstr(e, str);
}

void	apply_width_wchar(t_env *e, wchar_t c)
{
	int len;

	len = ft_wcharlen(c);
	if (e->width != 0)
		if (len < e->width)
		{
			TMPS = ft_strnew(e->width - len);
			TMPS = ft_memset(TMPS, ' ', e->width - len);
			if (e->fl_zero != ' ' && e->fl_neg == 0)
				TMPS = ft_memset(TMPS, '0', e->width - len);
			if (e->fl_neg == 0)
			{
				add_str(e, TMPS);
				add_wchar(e, c);
			}
			else
			{
				add_wchar(e, c);
				add_str(e, TMPS);
			}
			return ;
		}
	add_wchar(e, c);
}

void	apply_wchar(t_env *e)
{
	wchar_t value;

	value = (wchar_t)va_arg(ARGS, wchar_t);
	apply_width_wchar(e, value);
}
