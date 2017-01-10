/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:43:59 by momartin          #+#    #+#             */
/*   Updated: 2017/01/06 20:44:00 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define IMG e->img
# define WIDTH 640
# define HEIGHT 480
# define NBR ft_putnbr
# define STR ft_putstr
# define STRL ft_putendl
# define RED r_(color)
# define BLUE b_(color)
# define GREEN g_(color)
# define LD long double
# define FR e->fract
# define RATIO 2.5
# define USAGE "usage : (mandelbrot, julia, bship)\n"

# define MOUSE_L 1
# define MOUSE_R 2
# define MOUSE_U 5
# define MOUSE_D 4

typedef struct		s_fract
{
	LD		x1;
	LD		x2;
	LD		y1;
	LD		y2;
	int		maxit;
	LD		zoom_x;
	LD		zoom_y;
	LD		zoom_ratio;
	LD		tmp;
	LD		c_r;
	LD		c_i;
	LD		z_r;
	LD		z_i;
	int		i;
}					t_fract;

typedef struct		s_img
{
	void		*ptr;
	char		*data;
	int			**tab;
	int			w;
	int			h;
	int			bpp;
	int			size;
	int			endian;
}					t_img;
typedef struct		s_env
{
	t_fract		fract;
	char		wfract;
	void		*mlx;
	void		*win;
	t_img		*img;

}					t_env;

t_env				*init_all(t_env *e);
t_img				*init_img(int w, int h);
void				img_reset_tab(t_img *img);
void				img_pack(t_env *e);
void				put_pixel_img(t_img *img, int x, int y, int color);

void				init_mandelbrot(t_env *e);
void				reinit_mandelbrot(t_env *e);
void				iter_mandelbrot(t_env *e, int x, int y);
void				parse_mandelbrot(t_env *e);

void				init_julia(t_env *e);
void				reinit_julia(t_env *e);
void				iter_julia(t_env *e, int x, int y);
void				parse_julia(t_env *e);

void				init_ship(t_env *e);
void				reinit_ship(t_env *e);
void				iter_ship(t_env *e, int x, int y);
void				parse_ship(t_env *e);

void				init_it(t_env *e);
void				parse_it(t_env *e);
int					mouseaction(int keycode, int x, int y, t_env *e);
int					mousemove(int x, int y, t_env *e);

LD					ld_abs(LD nbr);

int					co_(int red, int green, int blue);
int					r_(int color);
int					g_(int color);
int					b_(int color);

#endif
