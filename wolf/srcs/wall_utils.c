/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:58:21 by momartin          #+#    #+#             */
/*   Updated: 2017/02/03 20:58:22 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	refresh_draw_wall(t_env *e)
{
	int x;
	int y;

	if (e->draw_start)
	{
		if (e->mouse_x <= e->draw_start_x || e->mouse_y <= e->draw_start_y)
			return ;
		y = e->draw_start_y - 1;
		while (++y < e->mouse_y)
		{
			x = e->draw_start_x - 1;
			while (++x < e->mouse_x)
				TVT[y][x] = co_(0, 0, 128);
		}
	}
}

void	new_wall(t_env *e)
{
	t_wall wall;

	if (PLX >= e->draw_start_x && PLX <= e->draw_end_x
		&& PLY >= e->draw_start_y && PLY <= e->draw_end_y)
		return ;
	if (e->draw_end_x > e->draw_start_x && e->draw_end_y > e->draw_start_y)
	{
		wall = create_wall(e->draw_start_x, e->draw_start_y,
			e->draw_end_x - e->draw_start_x,
			e->draw_end_y - e->draw_start_y);
		e->walls[e->nbrwalls] = wall;
		e->nbrwalls++;
	}
}
