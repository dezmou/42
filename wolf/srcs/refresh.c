/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 20:54:20 by momartin          #+#    #+#             */
/*   Updated: 2017/02/03 20:54:22 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	open_door(t_env *e)
{
	if (e->door_pos < 70)
	{
		WA[5].x += 2;
		e->door_pos += 1;
	}
	else
		e->door_opened = 1;
}

void	actualise(t_env *e)
{
	int nbr;

	nbr = -1;
	if (!e->door_opened && PLY > 400 && PLY < 640)
		open_door(e);
	if (e->ac_top_view)
	{
		img_reset_tab(TV);
		refresh_draw_wall(e);
		launch_all_rays(e);
		while (++nbr < e->nbrwalls)
			top_show_wall(e, nbr);
		top_show_player(e);
		img_pack(e, WIN, TV);
	}
	else
		launch_all_rays(e);
	img_reset_tab(VI);
	apply_view(e);
	img_merge(VI, e->hud, 0, 617);
	img_pack(e, RWIN, VI);
}

int		refresh(t_env *e)
{
	if (KL)
		pl_rotate(e, -ROTATE_SPEED);
	if (KR)
		pl_rotate(e, ROTATE_SPEED);
	if (KU)
		pl_move(e, SPEED);
	if (KD)
		pl_move(e, -SPEED);
	actualise(e);
	return (1);
}
