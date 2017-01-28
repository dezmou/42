/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:09:10 by momartin          #+#    #+#             */
/*   Updated: 2017/01/27 14:09:11 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	get_map(t_env *e)
{
	char	**tmp;
	int		y;

	y = -1;
	tmp = ft_strsplit(LINE, ' ');
	HEIGHT = ft_atoi(tmp[1]);
	WIDTH = ft_atoi(tmp[2]);
	apply_get_map(e);
	free_splited_str(tmp);
	apply_map_x(e);
}

void	get_nbrplayer(t_env *e)
{
	char **tmp;

	tmp = ft_strsplit(LINE, ' ');
	NBPL = tmp[2][1] - '0';
	free_splited_str(tmp);
	free(LINE);
	get_next_line(0, &LINE);
}

void	apply_get_map(t_env *e)
{
	char	**tmp;
	int		y;

	y = 0;
	free(LINE);
	get_next_line(0, &LINE);
	free(LINE);
	get_next_line(0, &LINE);
	while (!ft_strstr(LINE, "Piece "))
	{
		tmp = ft_strsplit(LINE, ' ');
		ft_strcpy(MAP[y], tmp[1]);
		free_splited_str(tmp);
		free(LINE);
		get_next_line(0, &LINE);
		y++;
	}
}

void	get_infos(t_env *e)
{
	while (get_next_line(0, &LINE))
	{
		e->nbrgame++;
		reinit(e);
		if (ft_strstr(LINE, "$$$ "))
			get_nbrplayer(e);
		if (ft_strstr(LINE, "lateau "))
			get_map(e);
		if (ft_strstr(LINE, "Piece "))
			get_piece(e);
		if (PRINT == 1)
			PMAP;
		apply_engine(e, -1, -1);
		free(LINE);
		e->map_is_malloc = 1;
	}
}
