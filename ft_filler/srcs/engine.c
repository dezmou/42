/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:08:08 by momartin          #+#    #+#             */
/*   Updated: 2017/01/27 14:08:09 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int		isplaceable(t_env *e, int x, int y)
{
	int neox;
	int neoy;
	int covered;

	covered = 0;
	neoy = -1;
	while (++neoy < PHEIGHT)
	{
		neox = -1;
		while (++neox < PWIDTH)
		{
			if (MAP[neoy + y][neox + x] == 'X' && PIECE[neoy][neox] == '*')
				covered += 1;
			if (MAP[neoy + y][neox + x] == 'O' && PIECE[neoy][neox] == '*')
				return (0);
		}
	}
	if (covered == 1)
		return (1);
	return (0);
}

int		get_distance_from_op(t_env *e, int ax, int ay)
{
	int x;
	int y;
	int tmp;
	int min;

	min = 99999;
	y = -1;
	while (++y < HEIGHT && (x = -1) != -2)
		while (++x < WIDTH)
			if (MAP[y][x] == 'O')
			{
				tmp = ft_abs(ax - x) + ft_abs(ay - y);
				if (tmp <= min)
					min = tmp;
			}
	return (min);
}

void	apply_engine(t_env *e, int x, int y)
{
	int min;
	int tmp;
	int finalx;
	int finaly;

	finalx = 0;
	finaly = 0;
	min = 99999;
	while (++y < HEIGHT - PHEIGHT && (x = -1) != -2)
		while (++x < WIDTH - PWIDTH)
		{
			if (isplaceable(e, x, y))
			{
				if ((tmp = get_distance_from_op(e, x, y)) < min)
				{
					min = tmp;
					finalx = x - CLN.min_x;
					finaly = y - CLN.min_y;
				}
			}
		}
	push(e, finalx, finaly);
}
