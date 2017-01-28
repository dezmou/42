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

#include "ft_filler.h"

void	reinit(t_env *e)
{
	e->width = 0;
	e->height = 0;
	e->p_width = 0;
	e->p_height = 0;
	e->over = 0;
	e->cleaner.min_x = 999999;
	e->cleaner.max_x = 0;
	e->cleaner.min_y = 999999;
	e->cleaner.max_y = 0;
	e->min_score = 999999;
}

void	init(t_env *e)
{
	e->map_is_malloc = 0;
	e->nbrplayer = 0;
	e->nbrgame = 1;
	reinit(e);
}
