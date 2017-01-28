/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 03:00:36 by momartin          #+#    #+#             */
/*   Updated: 2017/01/23 03:00:37 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_wchar(t_env *e, wchar_t c)
{
	NBRR += ft_putwchar(c);
}

void	add_wstr(t_env *e, wchar_t *str)
{
	int i;

	i = -1;
	while (str[++i])
		add_wchar(e, str[i]);
}

void	add_char(t_env *e, char c)
{
	ft_putchar(c);
	NBRR++;
}

void	add_str(t_env *e, char *str)
{
	int i;

	i = -1;
	TMPS = str;
	while (TMPS[++i] != '\0')
		NBRR++;
	ft_putstr(TMPS);
	free(TMPS);
}
