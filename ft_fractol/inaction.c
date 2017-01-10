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

#include "fract.h"

void		parse_it(t_env *e)
{
	if (e->wfract == 1)
		parse_mandelbrot(e);
	if (e->wfract == 2)
		parse_julia(e);
	if (e->wfract == 3)
		parse_ship(e);
}

void		init_it(t_env *e)
{
	if (e->wfract == 1)
		init_mandelbrot(e);
	if (e->wfract == 2)
		init_julia(e);
	if (e->wfract == 3)
		init_ship(e);
}

int			mousemove(int x, int y, t_env *e)
{
	if (x > 0 && y > 0)
	{
		FR.c_r = (LD)x / WIDTH * 4 - 2;
		FR.c_i = (LD)y / HEIGHT * 4 - 2;
		parse_it(e);
	}
	return (0);
}

int			mouseaction(int keycode, int x, int y, t_env *e)
{
	img_reset_tab(IMG);
	FR.x1 += (((LD)x - HEIGHT / 2) / WIDTH / 2) / FR.zoom_ratio * RATIO;
	FR.x2 += (((LD)x - HEIGHT / 2) / WIDTH / 2) / FR.zoom_ratio * RATIO;
	FR.y1 += (((LD)y - WIDTH / 2) / HEIGHT / 2) / FR.zoom_ratio * RATIO;
	FR.y2 += (((LD)y - WIDTH / 2) / HEIGHT / 2) / FR.zoom_ratio * RATIO;
	if (keycode == MOUSE_L || keycode == MOUSE_D)
	{
		FR.zoom_ratio *= 1.4;
		FR.maxit += 4;
	}
	if (keycode == MOUSE_R || keycode == MOUSE_U)
	{
		FR.zoom_ratio /= 1.4;
		FR.maxit += -4;
	}
	parse_it(e);
	return (0);
}
