/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:42:30 by momartin          #+#    #+#             */
/*   Updated: 2017/01/06 20:42:32 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void obj_set_relative(E)
{
	for (int i = 0; i < OB.size; i++)
	{
		VREL[i].x = VBASE[i].x + OB.posx ;
		VREL[i].y = VBASE[i].y + OB.posy ;
		VREL[i].z = VBASE[i].z;
	}
}

void obj_apply_pers(E)
{
	for (int i = 0; i < OB.size; i++)
	{
		VREL[i].x = (VREL[i].x + VREL[i].z);
		VREL[i].y = (VREL[i].y + VREL[i].z);
	}
}

void show_object(E)
{
	obj_set_relative(e);
	obj_apply_pers(e);
	for(int i = 0; i < OB.size; i++)
	{
		IMG->tab[(int)VREL[i].y + CENTER_H][(int)VREL[i].x + CENTER_W]
			= co_(0,0,0);
	}
}

void makeplane(E,int width,int height)
{
	int i;
	int neoz;

	i = 0;
	VBASE = (t_vector*)malloc(sizeof(t_vector) * width * height);
	VREL = (t_vector*)malloc(sizeof(t_vector) * width * height);
	for (int y = -(height / 2); y < (height / 2); y++)
	{
		for (int x = -(width / 2); x < (width / 2); x++)
		{
			VBASE[i].x = (LD)x;
			VBASE[i].y = (LD)y;
			VBASE[i].z = (LD)y;
			i += 1;
		}
	}
	OB.size = i;
	OB.posx = 0;
	OB.posy = 0;
}

int		main(int argc, char *argv[])
{
	t_env	*e;

	e = NULL;
	e = init_all(e);
	makeplane(e, 100,100);
	show_object(e);
	img_pack(e);
	mlx_mouse_hook(e->win, mouseaction, e);
	mlx_hook(e->win, 6, (1L << 6), mousemove, e);
	mlx_hook(e->win, 2, (1L << 0), key_func, e);
	mlx_loop(e->mlx);
	return (0);
}
