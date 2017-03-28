/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:55:16 by momartin          #+#    #+#             */
/*   Updated: 2017/02/03 20:55:18 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		get_color_wall(t_env *e, int i, int x, int y)
{
	int refx;
	int refy;
	int refyl;
	int refxl;

	refx = x - WA[i].x;
	refy = y - WA[i].y;
	refxl = WA[i].x + WA[i].width - x;
	refyl = WA[i].y + WA[i].height - y;
	if (refx <= refy && refx <= refxl && refx <= refyl)
		return (co_(128, 0, 0));
	if (refy <= refx && refy <= refxl && refy <= refyl)
		return (co_(0, 128, 0));
	if (refxl <= refx && refxl <= refy && refxl <= refyl)
		return (co_(0, 0, 128));
	if (refyl <= refx && refyl <= refy && refyl <= refxl)
		return (co_(128, 128, 0));
	return (1);
}

int		is_on_wall(t_env *e, int x, int y)
{
	int i;

	i = -1;
	while (++i < e->nbrwalls)
	{
		if ((x > WA[i].x && x < WA[i].x + WA[i].width) &&
			(y > WA[i].y && y < WA[i].y + WA[i].height))
		{
			e->color_wall[e->acti] = get_color_wall(e, i, x, y);
			return (1);
		}
	}
	return (0);
}

void	top_show_wall(t_env *e, int nbr)
{
	int x;
	int y;

	y = WA[nbr].y - 1;
	while (++y < WA[nbr].y + WA[nbr].height)
	{
		x = WA[nbr].x - 1;
		while (++x < WA[nbr].x + WA[nbr].width)
			TVT[y][x] = co_(128, 128, 128);
	}
}

t_wall	create_wall(int x, int y, int width, int height)
{
	t_wall wa;

	wa.x = x;
	wa.y = y;
	wa.width = width;
	wa.height = height;
	return (wa);
}

void	init_walls(t_env *e)
{
	WA[0] = create_wall(0, 0, TWIDTH, 30);
	WA[1] = create_wall(0, THEIGHT - 30, TWIDTH, 30);
	WA[2] = create_wall(0, 0, 30, THEIGHT);
	WA[3] = create_wall(TWIDTH - 30, 0, 30, THEIGHT);
	WA[4] = create_wall(700, 400, 30, 500);
	WA[5] = create_wall(730, 400, 150, 30);
	e->nbrwalls = 6;
}
