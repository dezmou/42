/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inaction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:43:00 by momartin          #+#    #+#             */
/*   Updated: 2017/01/06 20:43:02 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_func(int key, t_env *e)
{
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}

int			mousemove(int x, int y, t_env *e)
{
	return (0);
}

int			mouseaction(int keycode, int x, int y, t_env *e)
{
	return (0);
}
