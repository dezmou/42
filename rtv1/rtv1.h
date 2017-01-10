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

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include <math.h>


# define CENTER_H (HEIGHT / 2)
# define CENTER_W (WIDTH / 2)
# define WIDTH 640
# define HEIGHT 480

# define NBR ft_putnbr
# define STR ft_putstr
# define STRL ft_putendl
# define RED r_(color)
# define BLUE b_(color)
# define GREEN g_(color)

# define LD long double

# define E t_env *e
# define IMG e->img
# define OB e->object
# define VBASE e->object.v_base
# define VREL e->object.v_relative
# define VSHOW e->object.v_show

# define MOUSE_L 1
# define MOUSE_R 2
# define MOUSE_U 5
# define MOUSE_D 4


typedef struct		s_vector
{
	LD x;
	LD y;
	LD z;
}					t_vector;

typedef struct		s_obj
{
	t_vector 	*v_base;
	t_vector 	*v_relative;
	int 		size;
	LD			posx;
	LD			posy;
	LD			posz;
}					t_obj;

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
	int 		sizeobj;
	void		*mlx;
	void		*win;
	t_img		*img;
	t_obj 		object;
}					t_env;

t_env				*init_all(t_env *e);
t_img				*init_img(int w, int h);
void				img_reset_tab(t_img *img);
void				img_pack(t_env *e);
void				put_pixel_img(t_img *img, int x, int y, int color);
int					key_func(int key, t_env *e);

int					mouseaction(int keycode, int x, int y, t_env *e);
int					mousemove(int x, int y, t_env *e);

int					co_(int red, int green, int blue);
int					r_(int color);
int					g_(int color);
int					b_(int color);


#endif
