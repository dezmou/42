/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:54:55 by momartin          #+#    #+#             */
/*   Updated: 2017/02/03 21:54:58 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static	void	act_top_view(t_env *e)
{
	if (e->ac_top_view == 1)
	{
		img_reset_tab(TV);
		img_pack(e, WIN, TV);
		e->ac_top_view = 0;
	}
	else
		e->ac_top_view = 1;
}

int				keypress_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == KEY_LEFT)
		e->k_left = 1;
	if (keycode == KEY_RIGHT)
		e->k_right = 1;
	if (keycode == KEY_UP)
		KU = 1;
	if (keycode == KEY_DOWN)
		KD = 1;
	if (keycode == 78)
		if (e->dpi < 20)
			e->dpi *= 1.1;
	if (keycode == 69)
		if (e->dpi > 0.7)
			e->dpi *= 0.9;
	if (keycode == 83)
		act_top_view(e);
	return (1);
}

int				keyrel_hook(int keycode, t_env *e)
{
	if (keycode == KEY_LEFT)
		e->k_left = 0;
	if (keycode == KEY_RIGHT)
		e->k_right = 0;
	if (keycode == KEY_UP)
		KU = 0;
	if (keycode == KEY_DOWN)
		KD = 0;
	return (1);
}

int				mousemove(int x, int y, t_env *e)
{
	if (x > 0 && x < TWIDTH)
		e->mouse_x = x;
	if (y > 0 && y < THEIGHT)
		e->mouse_y = y;
	return (0);
}

int				mouseaction(int keycode, int x, int y, t_env *e)
{
	if (x < 0 || y < 0 || y > THEIGHT || x > TWIDTH)
		return (0);
	if (keycode == MOUSE_R)
	{
		if (!e->draw_start)
		{
			e->draw_start_x = x;
			e->draw_start_y = y;
			e->draw_start = 1;
		}
		else
		{
			e->draw_end_x = x;
			e->draw_end_y = y;
			e->draw_start = 0;
			new_wall(e);
		}
	}
	return (1);
}
