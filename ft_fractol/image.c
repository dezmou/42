/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:42:43 by momartin          #+#    #+#             */
/*   Updated: 2017/01/06 20:42:45 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

t_img		*init_img(int w, int h)
{
	t_img	*img;
	int		y;
	int		x;

	y = 0;
	if (!(img = (t_img*)malloc(sizeof(t_img))))
		exit(0);
	if (!(img->tab = (int **)malloc(sizeof(int*) * h)))
		exit(0);
	img->w = w;
	img->h = h;
	while (y < h)
	{
		if (!(img->tab[y] = (int*)malloc(sizeof(int) * w)))
			exit(0);
		x = 0;
		while (x < w)
		{
			img->tab[y][x] = -1;
			x++;
		}
		y++;
	}
	return (img);
}

void		img_reset_tab(t_img *img)
{
	int y;
	int x;

	y = -1;
	while (++y < img->h)
	{
		x = -1;
		while (++x < img->w)
			img->tab[y][x] = -1;
	}
}

void		img_pack(t_env *e)
{
	int x;
	int y;

	mlx_destroy_image(e->mlx, IMG->ptr);
	IMG->ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	IMG->data = mlx_get_data_addr(IMG->ptr, &(IMG->bpp), &(IMG->size),
		&(IMG->endian));
	y = -1;
	while (++y < IMG->h)
	{
		x = -1;
		while (++x < IMG->w)
		{
			if (IMG->tab[y][x])
				put_pixel_img(IMG, x, y, IMG->tab[y][x]);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, IMG->ptr, 0, 0);
}

void		put_pixel_img(t_img *img, int x, int y, int color)
{
	img->data[(x * img->bpp / 8) + (y * WIDTH *
		img->bpp / 8)] = (color & 0x0000ff);
	img->data[(x * img->bpp / 8) + (y * WIDTH *
		img->bpp / 8) + 1] = (color & 0x00ff00) >> 8;
	img->data[(x * img->bpp / 8) + (y * WIDTH *
		img->bpp / 8) + 2] = (color & 0xff0000) >> 16;
}
