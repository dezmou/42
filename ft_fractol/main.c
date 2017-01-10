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

#include "fract.h"

int		key_func(int key, t_env *e)
{
	char lapin;

	lapin = e->wfract;
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}

char	check_param(int argc, char *argv[])
{
	if (argc != 2)
	{
		STR(USAGE);
		exit(0);
	}
	if (ft_strstr(argv[1], "mandelbrot"))
		return (1);
	if (ft_strstr(argv[1], "julia"))
		return (2);
	if (ft_strstr(argv[1], "bship"))
		return (3);
	STR(USAGE);
	exit(0);
}

int		main(int argc, char *argv[])
{
	t_env	*e;
	char	w;

	w = check_param(argc, argv);
	e = NULL;
	e = init_all(e);
	e->wfract = w;
	init_it(e);
	parse_it(e);
	mlx_mouse_hook(e->win, mouseaction, e);
	if (e->wfract == 2)
		mlx_hook(e->win, 6, (1L << 6), mousemove, e);
	mlx_hook(e->win, 2, (1L << 0), key_func, e);
	mlx_loop(e->mlx);
	return (0);
}
