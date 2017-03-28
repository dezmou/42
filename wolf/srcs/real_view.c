/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:58:04 by momartin          #+#    #+#             */
/*   Updated: 2017/02/03 21:58:05 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	show_floor_top(t_env *e)
{
	int y;
	int x;

	y = -1;
	while (++y < (int)e->midy)
	{
		x = -1;
		while (++x < WIDTH)
		{
			VT[y][x] = co_(0, 0, y / 2);
		}
	}
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			VT[y][x] = co_(0, y - 350, 40);
		}
	}
}

int		dark(int color, int n)
{
	n = n / 5;
	return (co_(r_(color) - n, g_(color) - n, b_(color) - n));
}

void	apply_view(t_env *e)
{
	int		x;
	int		y;
	int		zouze;
	DB		test;

	show_floor_top(e);
	x = -1;
	while (++x < WIDTH)
	{
		test = ((277 * 700) / (DB)DIST[x] / 6);
		y = -1;
		zouze = 0;
		while (++y < test)
		{
			if (y < e->midy)
			{
				VT[y + (int)e->midy][x] = dark(e->color_wall[x], DIST[x]);
				VT[zouze + (int)e->midy][x] = dark(e->color_wall[x], DIST[x]);
			}
			zouze--;
		}
	}
}
