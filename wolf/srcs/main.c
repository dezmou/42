/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:59:31 by momartin          #+#    #+#             */
/*   Updated: 2017/01/11 19:59:32 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	img_merge(t_img *big, t_img *little, int x, int y)
{
	int neox;
	int neoy;

	neoy = -1;
	while (++neoy < little->h)
	{
		neox = -1;
		while (++neox < little->w)
			big->tab[neoy + y][neox + x] = little->tab[neoy][neox];
	}
}

void	pl_move(t_env *e, int f)
{
	int morex;
	int morey;

	morex = (PLP[3].x + PLP[2].x) * f / 10;
	morey = (PLP[3].y + PLP[2].y) * f / 10;
	apply_wall_block(e, morex, morey);
}

int		quit(void)
{
	exit(0);
}

int		main(void)
{
	t_env e;

	init_env(&e);
	mlx_hook(e.win, 2, KEYPRESSMASK, keypress_hook, &e);
	mlx_hook(e.win, 3, KEYRELMASK, keyrel_hook, &e);
	mlx_hook(e.rwin, 2, KEYPRESSMASK, keypress_hook, &e);
	mlx_hook(e.rwin, 3, KEYRELMASK, keyrel_hook, &e);
	mlx_hook(e.win, 6, (1L << 6), mousemove, &e);
	mlx_hook(e.win, 17, 1, &quit, NULL);
	mlx_hook(e.rwin, 17, 1, &quit, NULL);
	mlx_mouse_hook(e.win, mouseaction, &e);
	mlx_loop_hook(e.mlx, refresh, &e);
	mlx_loop(e.mlx);
	return (0);
}
