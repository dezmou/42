/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:00:06 by momartin          #+#    #+#             */
/*   Updated: 2017/02/03 21:00:07 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		init_ray(t_env *e, DB angle)
{
	RA.x = 0;
	RA.y = 0;
	RA.ybase = 0;
	RA.xbase = 0;
	RA.rangle = (DB)(angle) * 0.0174533;
}

DB				launch_ray(t_env *e, DB angle, DB fish)
{
	DB tmp;

	fish *= 0.0174533;
	init_ray(e, angle);
	while (!is_on_wall(e, PLX + RA.x, PLY + RA.y))
	{
		RA.y = RA.ybase;
		RA.x = RA.xbase;
		tmp = RA.x;
		RA.y = (RA.y / cos(fish));
		RA.x = cos(RA.rangle) * RA.x - sin(RA.rangle) * RA.y;
		RA.y = sin(RA.rangle) * tmp + cos(RA.rangle) * RA.y;
		TVT[(int)(PLY + RA.y)][(int)(PLX + RA.x)] = co_(255, 0, 0);
		RA.ybase += -e->dpi;
	}
	return ((fabs(RA.ybase)));
}

void			launch_all_rays(t_env *e)
{
	int		i;
	DB		tmpangle;
	DB		inc;
	DB		fish;

	fish = -(FIELD / 2);
	tmpangle = (DB)PL.angle - FIELD / 2;
	i = -1;
	inc = FIELD / WIDTH;
	while (++i < WIDTH)
	{
		e->acti = i;
		e->distance[i] = launch_ray(e, tmpangle, fabs(fish));
		e->ray_act_angle = tmpangle;
		tmpangle += inc;
		fish += inc;
	}
}
