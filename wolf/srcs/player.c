/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:02:45 by momartin          #+#    #+#             */
/*   Updated: 2017/02/03 21:02:48 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	pl_put_rect(t_img *img, int x, int y, int color)
{
	int sx;
	int sy;

	sy = -1;
	while (++sy < 6 && (sx = -1) != -2)
		while (++sx < 6)
			img->tab[y + sy - 3][x + sx - 3] = color;
}

void	top_show_player(t_env *e)
{
	pl_put_rect(TV, PLP[0].x + PLX, PLP[0].y + PLY, co_(128, 0, 128));
	pl_put_rect(TV, PLP[1].x + PLX, PLP[1].y + PLY, co_(128, 0, 128));
	pl_put_rect(TV, PLP[2].x + PLX, PLP[2].y + PLY, co_(0, 128, 0));
}

void	pl_rotate(t_env *e, int angle)
{
	DB	rangle;
	DB	tmp;

	PL.angle += angle;
	if (abs(PL.angle) == 360)
		PL.angle = 0;
	rangle = (DB)(angle) * 0.0174533;
	tmp = PLP[0].x;
	PLP[0].x = cos(rangle) * PLP[0].x - sin(rangle) * PLP[0].y;
	PLP[0].y = sin(rangle) * tmp + cos(rangle) * PLP[0].y;
	tmp = PLP[1].x;
	PLP[1].x = cos(rangle) * PLP[1].x - sin(rangle) * PLP[1].y;
	PLP[1].y = sin(rangle) * tmp + cos(rangle) * PLP[1].y;
	tmp = PLP[2].x;
	PLP[2].x = cos(rangle) * PLP[2].x - sin(rangle) * PLP[2].y;
	PLP[2].y = sin(rangle) * tmp + cos(rangle) * PLP[2].y;
}

void	init_player(t_env *e)
{
	PLX = 850;
	PLY = 850;
	PLP[0].x = -10;
	PLP[0].y = 10;
	PLP[1].x = 10;
	PLP[1].y = 10;
	PLP[2].x = 0;
	PLP[2].y = -10;
	PLP[3].x = 0;
	PLP[3].y = 0;
	PL.angle = 0;
}

void	apply_wall_block(t_env *e, int morex, int morey)
{
	int nbr;

	nbr = -1;
	while (++nbr < e->nbrwalls)
	{
		if ((PLY + morey > WA[nbr].y &&
			PLY + morey < WA[nbr].y + WA[nbr].height) &&
			(PLX + morex > WA[nbr].x &&
			PLX + morex < WA[nbr].x + WA[nbr].width))
		{
			morey = 0;
			morex = 0;
		}
	}
	PLY += morey;
	PLX += morex;
}
