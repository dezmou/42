/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:43:20 by momartin          #+#    #+#             */
/*   Updated: 2017/01/06 20:43:22 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		init_julia(t_env *e)
{
	FR.c_r = 0.285;
	FR.c_i = 0.01;
	FR.z_r = 0;
	FR.z_i = 0;
	FR.x1 = 0;
	FR.x2 = 0;
	FR.y1 = 0;
	FR.y2 = 0;
	FR.zoom_ratio = 0.5;
	FR.zoom_x = WIDTH / (1.5 + 1.5);
	FR.zoom_y = HEIGHT / (1.2 + 1.2);
	FR.tmp = 0;
	FR.i = 0;
	FR.maxit = 70;
}

void		reinit_julia(t_env *e)
{
	FR.z_r = 0.285;
	FR.z_i = 0.01;
	FR.i = 0;
}

void		iter_julia(t_env *e, int x, int y)
{
	FR.z_r = 1.0 * (x - WIDTH / 2) / (0.5 * FR.zoom_ratio * WIDTH) + FR.x1;
	FR.z_i = (y - HEIGHT / 2) / (0.5 * FR.zoom_ratio * WIDTH) + FR.y1;
	while ((FR.z_r * FR.z_r + FR.z_i * FR.z_i) < 4 && (FR.i < FR.maxit))
	{
		FR.tmp = FR.z_r;
		FR.z_r = FR.z_r * FR.z_r - FR.z_i * FR.z_i + FR.c_r;
		FR.z_i = 2 * FR.z_i * FR.tmp + FR.c_i;
		FR.i += 1;
	}
}

void		parse_julia(t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			reinit_julia(e);
			iter_julia(e, x, y);
			if (FR.i == FR.maxit)
				IMG->tab[y][x] = co_(x / 6, y / 6, 20);
			else
				IMG->tab[y][x] = co_((int)FR.z_i, (int)FR.zoom_ratio, FR.i);
		}
	}
	img_pack(e);
}
