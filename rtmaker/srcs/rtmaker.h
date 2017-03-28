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

#ifndef RTMAKER_H
# define RTMAKER_H

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include <gtk/gtk.h>
#include <cairo.h>

# define WIDTH 2300
# define HEIGHT 1250

# define WIN e->win
# define IMG e->image
# define BUT e->buttons
# define OBJ e->objs
# define SOBJ e->objs[e->selected_obj]
# define IOBJM e->objs[i].mat
# define CAM e->objs[0]
# define SSLICES SOBJ.slices


# define I_TOP 1
# define I_FRONT 2
# define I_LEFT 3

# define I_CAMERA 0
# define I_SPHERE 1
# define I_PLANE 2
# define I_CYLINDER 3
# define I_CONE 4
# define I_SELECT 5
# define I_CIBLE 6
# define I_LIGHT 7
# define I_SLICE 8

# define I_X 1
# define I_Y 2
# define I_Z 3

# define DB double
# define GTW GtkWidget

typedef struct 	s_vect
{
	DB	x;
	DB 	y;
	DB 	z;
}				t_vect;
typedef struct 	s_material
{
	int			red;
	int 		green;
	int 		blue;
	int 		transparency;
	int 		refraction;
	int 		brillance;
	int 		reflection;
	int 		bump_mapping;
}				t_material;


typedef struct 	s_obj
{
	int 	type;
	t_vect 	pos;
	t_vect 	ori;
	t_material mat;

	GTW 	*top_img;
	GTW 	*front_img;
	GTW 	*left_img;

	GTW 	*top_vect;
	GTW 	*front_vect;
	GTW 	*left_vect;

	int 	radius;
	int 	slice_index;
}				t_obj;

typedef struct	s_env
{
	GTW			*win;
	GTW			*fixed;
	GTW 		*background;
	GTW 		*rendu;

	GTW 		*b_render;
	GTW 		*b_add_sphere;
	GTW 		*b_add_plane;
	GTW 		*b_add_cylinder;
	GTW 		*b_add_cone;
	GTW 		*b_add_light;
	GTW 		*b_color_pick;
	GTW 		*b_add_slice;

	GTW 		*sc_red;
	GTW 		*sc_blue;
	GTW 		*sc_green;
	GTW 		*sc_brillance;
	GTW 		*sc_refraction;
	GTW 		*sc_transparency;
	GTW 		*sc_reflection;
	GTW 		*sc_bump_mapping;

	GTW 		*sc_radius;

	GTW 		*in_color;
	GTW 		*show_color;

	GTW 		*la_brillance;
	GTW 		*la_refraction;
	GTW 		*la_transparency;
	GTW 		*la_reflection;
	GTW 		*la_bump_mapping;
	GTW 		*la_radius;

	cairo_surface_t *surface;

	t_obj 		objs[100];
	int 		nbrobjs;
	char 		sprites[10][100];

	GTW 		*t_select_sprite;
	GTW 		*f_select_sprite;
	GTW 		*l_select_sprite;

	int 		active_view;
	int 		selected_obj;
	int 		apply_slice_nbr;

	int 		t_x;
	int 		t_y;
	int 		f_x;
	int 		f_y;
	int 		l_x;
	int 		l_y;

}				t_env;

void 	init_env(t_env *e);

int 	view_by_pos(int x, int y);
void 	viewpos_by_pos(int *x, int *y);
void 	viewpos_by_vect(t_env *e, t_vect v);

void add_obj(t_env *e, int type);
void add_sphere(GTW *widget, t_env *e);
void add_plane(GTW *widget, t_env *e);
void add_cylinder(GTW *widget, t_env *e);
void add_cone(GTW *widget, t_env *e);
void add_light(GTW *widget, t_env *e);
void add_slice(GTW *widget, t_env *e);
void show_obj(t_env *e, t_obj *obj);
void move_obj(t_env *e, t_obj *obj, int x, int y);
void refresh(t_env *e);
void vect_by_pos(t_vect *v, int x, int y);
void move_select_sprite(t_env *e);
void move_obj(t_env *e, t_obj *obj, int x, int y);
void select_obj(t_env *e, int x, int y);
void show_selected_obj(t_env *e);
void hide_cible(t_env *e);
void rotate(t_env *e, t_obj *obj, int axe, int angle);
void act_ori_pos(t_env *e, t_obj *obj);
void render(GTW *widget, t_env *e);
void select_obj_act_material_buttons(t_env *e);
int	co_(int red, int green, int blue);
int	r_(int color);
int	g_(int color);
int	b_(int color);
void set_input_color_from_scale(t_env *e);
void paint_color(t_env *e);
void disable_widgets(t_env *e);

#endif

/*
top
x 813 1612
y 0 602

front
x 813 1612
y 615 1215

left
x 0 800
y 615 1215
*/
