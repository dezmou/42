/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:43:50 by momartin          #+#    #+#             */
/*   Updated: 2017/01/06 20:43:51 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		init_ship(t_env *e)
{
	FR.c_r = 0;
	FR.c_i = 0;
	FR.z_r = 0;
	FR.z_i = 0;
	FR.x1 = 0;
	FR.x2 = 0;
	FR.y1 = 0;
	FR.y2 = 0;
	FR.zoom_ratio = 0.5;
	FR.zoom_x = WIDTH / (1.6 + 1.1);
	FR.zoom_y = HEIGHT / (1.7 + 0.7);
	FR.tmp = 0;
	FR.i = 0;
	FR.maxit = 60;
}

void		reinit_ship(t_env *e)
{
	FR.z_r = 0;
	FR.z_i = 0;
	FR.i = 0;
}

LD			ld_abs(LD nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void		iter_ship(t_env *e, int x, int y)
{
	FR.c_r = 1.0 * (x - WIDTH / 2) / (0.5 * FR.zoom_ratio * WIDTH) + FR.x1;
	FR.c_i = (y - HEIGHT / 2) / (0.5 * FR.zoom_ratio * HEIGHT) + FR.y1;
	while ((FR.z_r * FR.z_r + FR.z_i * FR.z_i) < 4 && (FR.i < FR.maxit))
	{
		FR.tmp = FR.z_r;
		FR.z_r = FR.z_r * FR.z_r - FR.z_i * FR.z_i + FR.c_r;
		FR.z_i = 2 * ld_abs(FR.z_i) * ld_abs(FR.tmp) + FR.c_i;
		FR.i += 1;
	}
}

void		parse_ship(t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			reinit_ship(e);
			iter_ship(e, x, y);
			if (FR.i == FR.maxit)
				IMG->tab[y][x] = co_(x / 6, y / 6, 20);
			else
				IMG->tab[y][x] = co_(0, FR.i, FR.i);
		}
	}
	img_pack(e);
}
