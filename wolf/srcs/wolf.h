/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:59:46 by momartin          #+#    #+#             */
/*   Updated: 2017/01/11 19:59:48 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "./libft/libft.h"
# include <math.h>
# include <fcntl.h>

# define SPEED 8
# define ROTATE_SPEED 8
# define FIELD 60.
# define WINNAME "Wolf 3D"
# define TVNAME "Wolf Map Builder pro 8.14 | Unregistred "

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP	126
# define KEY_DOWN 125
# define MOUSE_L 1
# define MOUSE_R 2
# define MOUSE_U 5
# define MOUSE_D 4

# define KEYPRESSEVENT 2
# define KEYPRESSMASK (1L << 0)
# define KEYRELEVENT 3
# define KEYRELMASK (1L << 1)
# define WIN e->win
# define MLX e->mlx
# define RWIN e->rwin
# define WIDTH 700
# define HEIGHT 700
# define TWIDTH 900
# define THEIGHT 900
# define TV e->top_view
# define TVT e->top_view->tab
# define PLP e->player.points
# define PL e->player
# define PLX e->player.posx
# define PLY e->player.posy
# define PLA e->player.angle
# define KL e->k_left
# define KR e->k_right
# define KU e->k_up
# define DB double
# define KD e->k_down
# define WA e->walls
# define RA e->ray
# define VI e->view
# define VT e->view->tab
# define DIST e->distance

typedef struct		s_ray
{
	DB				x;
	DB				y;
	DB				rangle;
	DB				ybase;
	DB				xbase;
	DB				inc;
}					t_ray;

typedef struct		s_wall
{
	int				x;
	int				y;
	int				width;
	int				height;
}					t_wall;

typedef struct		s_point
{
	DB				x;
	DB				y;

}					t_point;

typedef struct		s_player
{
	int				posx;
	int				posy;
	t_point			points[5];
	int				angle;
}					t_player;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				**tab;
	int				w;
	int				h;
	int				bpp;
	int				size;
	int				endian;
	int				inited;

}					t_img;

typedef struct		s_toolimg
{
	char			str[3];
	int				color;
}					t_toolimg;

typedef struct		s_img_reader
{
	char			rendu;
	int				fd;
	char			*line;
	t_img			*img;
	t_toolimg		toli[256];
	int				indextoli;
	int				width;
	int				height;
	int				index_h;
}					t_img_reader;

typedef struct		s_env
{
	void			*win;
	void			*mlx;
	void			*rwin;
	t_img			*top_view;
	t_img			*view;
	t_img			*hud;
	t_player		player;
	t_wall			walls[1000];
	t_ray			ray;
	int				nbrwalls;
	int				k_left;
	int				k_right;
	int				k_up;
	int				k_down;
	int				distance[WIDTH];
	int				ac_top_view;
	DB				dpi;
	DB				midy;
	int				ray_act_angle;
	int				ret_color_ray;
	int				color_wall[WIDTH];
	int				mouse_x;
	int				mouse_y;
	int				draw_start;
	int				draw_start_x;
	int				draw_start_y;
	int				draw_end_x;
	int				draw_end_y;
	int				acti;
	int				door_opened;
	int				door_pos;
}					t_env;

void				init_env(t_env *e);
void				put_pixel_img(t_img *img, int x, int y, int color);
t_img				*init_img(int w, int h);
void				init_player(t_env *e);
void				img_reset_tab(t_img *img);
void				img_pack(t_env *e, void *win, t_img *img);
void				top_show_player(t_env *e);
int					co_(int red, int green, int blue);
int					r_(int color);
int					g_(int color);
int					b_(int color);
void				pl_rotate(t_env *e, int angle);
void				pl_move(t_env *e, int f);
int					keypress_hook(int keycode, t_env *e);
int					keyrel_hook(int keycode, t_env *e);
int					refresh(t_env *e);
void				actualise(t_env *e);
void				init_walls(t_env *e);
void				top_show_wall(t_env *e, int nbr);
t_wall				create_wall(int x, int y, int width, int height);
DB					launch_ray(t_env *e, DB angle, DB fish);
int					is_on_wall(t_env *e, int x, int y);
void				launch_all_rays(t_env *e);
void				apply_view(t_env *e);
void				refresh_draw_wall(t_env *e);
void				new_wall(t_env *e);
int					mousemove(int x, int y, t_env *e);
int					mouseaction(int keycode, int x, int y, t_env *e);
void				apply_view(t_env *e);
void				show_floor_top(t_env *e);
t_img				*load_image(char *filename);
void				free_splited_str(char **str);
void				img_merge(t_img *big, t_img *little, int x, int y);
void				apply_wall_block(t_env *e, int morex, int morey);

#endif
