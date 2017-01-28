/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:17:02 by momartin          #+#    #+#             */
/*   Updated: 2017/01/27 14:17:04 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	set_piece_clean(t_env *e)
{
	int x;
	int y;

	y = -1;
	while (++y < PHEIGHT)
	{
		x = -1;
		while (PIECE[y][++x])
		{
			if (PIECE[y][x] == '*')
			{
				if (x <= CLN.min_x)
					CLN.min_x = x;
				if (x >= CLN.max_x)
					CLN.max_x = x;
				if (y <= CLN.min_y)
					CLN.min_y = y;
				if (y >= CLN.max_y)
					CLN.max_y = y;
			}
		}
	}
}

void	tmp_to_piece(t_env *e)
{
	int y;
	int x;

	y = -1;
	x = -1;
	while (++y < PHEIGHT)
	{
		x = -1;
		while (++x < PWIDTH)
			PIECE[y][x] = e->tmppiece[y][x];
	}
}

void	clean_piece(t_env *e, int neox, int neoy)
{
	int y;
	int x;

	y = -1;
	set_piece_clean(e);
	while (++y < PHEIGHT)
	{
		x = -1;
		neox = -1;
		if (y >= CLN.min_y && y <= CLN.max_y)
		{
			e->tmppiece[++neoy][CLN.max_x - CLN.min_x + 1] = 0;
			while (++x < PWIDTH)
				if (x >= CLN.min_x && x <= CLN.max_x)
					e->tmppiece[neoy][++neox] = PIECE[y][x];
		}
	}
	PHEIGHT = CLN.max_y - CLN.min_y + 1;
	PWIDTH = CLN.max_x - CLN.min_x + 1;
	tmp_to_piece(e);
}

void	get_piece(t_env *e)
{
	char	**tmp;
	int		y;

	y = -1;
	tmp = ft_strsplit(LINE, ' ');
	PHEIGHT = ft_atoi(tmp[1]);
	PWIDTH = ft_atoi(tmp[2]);
	while (++y < PHEIGHT)
	{
		free(LINE);
		get_next_line(0, &LINE);
		ft_strcpy(PIECE[y], LINE);
	}
	free_splited_str(tmp);
	clean_piece(e, -1, -1);
}
