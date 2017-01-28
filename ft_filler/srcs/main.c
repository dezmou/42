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

#include "ft_filler.h"

void	printmap(t_env *e)
{
	int		y;
	int		x;
	char	act;

	act = 'y';
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (MAP[y][x] == 'X' && act != 'X')
				ft_putstr_fd("\x1B[31m", 2);
			if (MAP[y][x] == 'O' && act != 'O')
				ft_putstr_fd("\x1B[34m", 2);
			if (MAP[y][x] == '.' && act != '.')
				ft_putstr_fd("\x1B[32m", 2);
			ft_putchar_fd(MAP[y][x], 2);
			act = MAP[y][x];
		}
		ft_putchar_fd('\n', 2);
	}
	ft_putstr_fd("\n\n\n\n", 2);
}

void	push(t_env *e, int x, int y)
{
	ft_printf("%d %d\n", y, x);
}

int		main(void)
{
	t_env e;

	init(&e);
	get_infos(&e);
	return (0);
}
