/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:43:10 by momartin          #+#    #+#             */
/*   Updated: 2017/01/06 20:43:11 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_env		*init_all(t_env *e)
{
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		exit(0);
	IMG = init_img(WIDTH, HEIGHT);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Fractol");
	IMG->ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	IMG->data = mlx_get_data_addr(IMG->ptr,
		&(IMG->bpp), &(IMG->size), &(IMG->endian));
	return (e);
}
