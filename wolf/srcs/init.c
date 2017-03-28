/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:10:57 by momartin          #+#    #+#             */
/*   Updated: 2017/01/11 20:10:59 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		free_splited_str(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void		init_hud(t_env *e)
{
	e->hud = load_image("hud.xpm");
}

void		init_env(t_env *e)
{
	MLX = mlx_init();
	WIN = mlx_new_window(e->mlx, TWIDTH, THEIGHT, TVNAME);
	RWIN = mlx_new_window(e->mlx, WIDTH, HEIGHT, WINNAME);
	TV = init_img(TWIDTH, THEIGHT);
	VI = init_img(WIDTH, HEIGHT);
	init_hud(e);
	init_player(e);
	e->k_left = 0;
	e->k_right = 0;
	e->dpi = 2;
	e->midy = HEIGHT / 2;
	e->ac_top_view = 0;
	e->mouse_x = 0;
	e->mouse_y = 0;
	e->draw_start = 0;
	e->door_opened = 0;
	e->door_pos = 0;
	KU = 0;
	KD = 0;
	init_walls(e);
}
