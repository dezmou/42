/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:15:59 by momartin          #+#    #+#             */
/*   Updated: 2017/01/27 14:16:01 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	free_splited_str(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	apply_map_x(t_env *e)
{
	int y;
	int x;

	if (e->nbrplayer == 1)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
			{
				if (MAP[y][x] == 'O')
				{
					MAP[y][x] = 'X';
					continue ;
				}
				if (MAP[y][x] == 'X')
					MAP[y][x] = 'O';
			}
		}
	}
}
