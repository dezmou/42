/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 20:10:57 by momartin          #+#    #+#             */
/*   Updated: 2017/01/11 20:10:59 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmaker.h"


gboolean scroll(GTW *event, GdkEventScroll *zouze, t_env *e)
{
	int angle;
	int x;
	int y;

	x = (int)zouze->x;
	y = (int)zouze->y;
	angle = -10;
	if (zouze->direction == GDK_SCROLL_UP)
		angle = 10;
	if (view_by_pos(x, y) == I_TOP)
		rotate(e, &SOBJ, I_Z, angle);
	if (view_by_pos(x, y) == I_FRONT)
		rotate(e, &SOBJ, I_Y, angle);
	if (view_by_pos(x, y) == I_LEFT)
		rotate(e, &SOBJ, I_X, angle);
	act_ori_pos(e, &SOBJ);
	refresh(e);

	return (TRUE);
}

gboolean click(GTW *event, GdkEventButton *zouze, t_env *e)
{
	int x;
	int y;

	x = (int)zouze->x;
	y = (int)zouze->y;
	if (zouze->button == 3)
		move_obj(e, &SOBJ, x, y);
	if (zouze->button == 1)
		select_obj(e, x, y);
	refresh(e);
	return (TRUE);
}

void rotate(t_env *e, t_obj *obj, int axe, int angle)
{
	DB rangle;
	DB tmp;

	rangle = angle * 0.0174533;
	if (axe == I_Z)
	{
		tmp = obj->ori.x;
		obj->ori.x = cos(rangle) * obj->ori.x - sin(rangle) * obj->ori.y;
		obj->ori.y = sin(rangle) * tmp + cos(rangle) * obj->ori.y;
	}
	if (axe == I_X)
	{
		tmp = obj->ori.y;
		obj->ori.y = cos(rangle) * obj->ori.y - sin(rangle) * obj->ori.z;
		obj->ori.z = sin(rangle) * tmp + cos(rangle) * obj->ori.z;
	}
	if (axe == I_Y)
	{
		tmp = obj->ori.x;
		obj->ori.x = cos(rangle) * obj->ori.x + sin(rangle) * obj->ori.z;
		obj->ori.z = -sin(rangle) * tmp + cos(rangle) * obj->ori.z;
	}
}

void init_vars(t_env *e)
{
	e->selected_obj = 0;
	e->active_view = 0;
	e->nbrobjs = -1;
	e->apply_slice_nbr = 0;
	ft_strcpy(e->sprites[I_CAMERA], "sprites/camera.png");
	ft_strcpy(e->sprites[I_SPHERE], "sprites/sphere.png");
	ft_strcpy(e->sprites[I_CYLINDER], "sprites/cylinder.png");
	ft_strcpy(e->sprites[I_PLANE], "sprites/plane.png");
	ft_strcpy(e->sprites[I_CONE], "sprites/cone.png");
	ft_strcpy(e->sprites[I_SELECT], "sprites/select.png");
	ft_strcpy(e->sprites[I_CIBLE], "sprites/cible.png");
	ft_strcpy(e->sprites[I_LIGHT], "sprites/light.png");
	ft_strcpy(e->sprites[I_SLICE], "sprites/cisor.png");
	e->surface = NULL;
}



void refresh(t_env *e)
{
	move_select_sprite(e);
	gtk_widget_show_all(WIN);
	hide_cible(e);
}

int is_input_color_valid(const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if ( (str[i] < 'A' || str[i] > 'F') && (str[i] < 'a' || str[i] > 'f')
			&& (str[i] < '0' || str[i] > '9'))
			return (0);
	if (i != 6)
		return (0);
	return (1);
}

char *str_to_upper(char *str)
{
	int i;
	char *strr;

	strr = str;
	i = -1;
	while (strr[++i])
		if (strr[i] >= 'a' && strr[i] <= 'z')
			strr[i] -= 32;
	return (strr);
}

void set_scales_from_input_color(t_env *e)
{
	int color;
	char *in;

	in = ft_strdup((char*)gtk_entry_get_text(GTK_ENTRY(e->in_color)));
	in = str_to_upper(in);
	color = ft_atoi_base(in, 16);
	free(in);
	SOBJ.mat.red = r_(color);
	SOBJ.mat.green = g_(color);
	SOBJ.mat.blue = b_(color);
	gtk_range_set_value(GTK_RANGE(e->sc_red), (double)SOBJ.mat.red);
	gtk_range_set_value(GTK_RANGE(e->sc_green), (double)SOBJ.mat.green);
	gtk_range_set_value(GTK_RANGE(e->sc_blue), (double)SOBJ.mat.blue);
}

void set_input_color_from_scale(t_env *e)
{
	char *final;
	int color;

	color = co_(SOBJ.mat.red, SOBJ.mat.green, SOBJ.mat.blue);
	final = ft_itoa_base(color, 16);
	gtk_entry_set_text(GTK_ENTRY(e->in_color), final);
	paint_color(e);
	refresh(e);
}

void input_color_change(GtkEntry *entry, t_env *e)
{
	const char *str;

	str = gtk_entry_get_text(GTK_ENTRY(e->in_color));
	if (!is_input_color_valid(str))
		set_input_color_from_scale(e);
	else
		set_scales_from_input_color(e);
}





/*
#################################################################################################
SCALE CALLBACK

*/

void color_change_red(GtkRange *range, t_env *e)
{
	SOBJ.mat.red = (int)gtk_range_get_value(GTK_RANGE(e->sc_red));
	set_input_color_from_scale(e);
}
void color_change_green(GtkRange *range, t_env *e)
{
	SOBJ.mat.green = (int)gtk_range_get_value(GTK_RANGE(e->sc_green));
	set_input_color_from_scale(e);
}
void color_change_blue(GtkRange *range, t_env *e)
{
	SOBJ.mat.blue = (int)gtk_range_get_value(GTK_RANGE(e->sc_blue));
	set_input_color_from_scale(e);
}
void transparency_change(GtkRange *range, t_env *e)
{
	SOBJ.mat.transparency = (int)gtk_range_get_value(GTK_RANGE(e->sc_transparency));
}
void refraction_change(GtkRange *range, t_env *e)
{
	SOBJ.mat.refraction = (int)gtk_range_get_value(GTK_RANGE(e->sc_refraction));
}
void brillance_change(GtkRange *range, t_env *e)
{
	SOBJ.mat.brillance = (int)gtk_range_get_value(GTK_RANGE(e->sc_brillance));
}
void reflection_change(GtkRange *range, t_env *e)
{
	SOBJ.mat.reflection = (int)gtk_range_get_value(GTK_RANGE(e->sc_reflection));
}
void bump_mapping_change(GtkRange *range, t_env *e)
{
	SOBJ.mat.bump_mapping = (int)gtk_range_get_value(GTK_RANGE(e->sc_bump_mapping));
}
void radius_change(GtkRange *range, t_env *e)
{
	SOBJ.radius = (int)gtk_range_get_value(GTK_RANGE(e->sc_radius));
}
//###############################################################################################





gboolean do_cairo(GTW *widget, cairo_t *cr, t_env *e)
{
	cairo_set_source_surface(cr, e->surface, 0, 0);
	cairo_paint(cr);

	return (FALSE);

}

void paint_color(t_env *e)
{
  cairo_t *cr;

  cr = cairo_create (e->surface);
  cairo_set_source_rgb (cr, (float)SOBJ.mat.red/255, (float)SOBJ.mat.green/255, (float)SOBJ.mat.blue/255);
  cairo_paint (cr);
  cairo_destroy (cr);
}

gboolean do_cairo_configure(GTW *widget, GdkEventConfigure *event, t_env *e)
{
	if (e->surface)
		cairo_surface_destroy(e->surface);

	e->surface = gdk_window_create_similar_surface(gtk_widget_get_window(widget),
		CAIRO_CONTENT_COLOR,
		gtk_widget_get_allocated_width(widget),
		gtk_widget_get_allocated_height(widget));
		paint_color(e);
		return TRUE;
}

void init_buttons(t_env *e)
{
	e->b_render = gtk_button_new_with_label("Render");
	e->b_add_sphere = gtk_button_new_with_label("Add Sphere");
	e->b_add_plane = gtk_button_new_with_label("Add Plane");
	e->b_add_cylinder = gtk_button_new_with_label("Add Cylinder");
	e->b_add_cone = gtk_button_new_with_label("Add Cone");
	e->b_add_light = gtk_button_new_with_label("Add Light");
	e->b_add_slice = gtk_button_new_with_label("Add Slice");
	//gtk_widget_set_sensitive(e->b_add_slice, FALSE);
	e->sc_red = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 255, 2);
	e->sc_green = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 255, 2);
	e->sc_blue = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 255, 2);
	e->in_color = gtk_entry_new();
	e->show_color = gtk_drawing_area_new();
	e->la_brillance = gtk_label_new("Brillance");
	e->sc_brillance = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
	e->la_refraction = gtk_label_new("Refraction");
	e->sc_refraction = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
	e->la_transparency = gtk_label_new("Transparence");
	e->sc_transparency = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
	e->la_reflection = gtk_label_new("Reflection");
	e->sc_reflection = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
	e->la_bump_mapping = gtk_label_new("Bump Mapping");
	e->sc_bump_mapping = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);
	e->la_radius = gtk_label_new("Radius");
	e->sc_radius = gtk_scale_new_with_range(GTK_ORIENTATION_HORIZONTAL, 0, 100, 1);

	gtk_widget_set_size_request(e->b_render, 110, 110);
	gtk_widget_set_size_request(e->b_add_sphere, 110, 40);
	gtk_widget_set_size_request(e->b_add_plane, 110, 40);
	gtk_widget_set_size_request(e->b_add_cylinder, 110, 40);
	gtk_widget_set_size_request(e->b_add_cone, 110, 40);
	gtk_widget_set_size_request(e->b_add_light, 110, 40);
	gtk_widget_set_size_request(e->b_add_slice, 110, 40);
	gtk_widget_set_size_request(e->sc_red, 180, 40);
	gtk_widget_set_size_request(e->sc_green, 180, 40);
	gtk_widget_set_size_request(e->sc_blue, 180, 40);
	gtk_widget_set_size_request(e->sc_brillance, 180, 40);
	gtk_widget_set_size_request(e->sc_refraction, 180, 40);
	gtk_widget_set_size_request(e->sc_transparency, 180, 40);
	gtk_widget_set_size_request(e->sc_reflection, 180, 40);
	gtk_widget_set_size_request(e->sc_bump_mapping, 180, 40);
	gtk_widget_set_size_request(e->sc_radius, 180, 40);
	gtk_entry_set_max_length (GTK_ENTRY (e->in_color), 6);
	gtk_widget_set_size_request(e->show_color, 57, 32);

	gtk_fixed_put(GTK_FIXED(e->fixed), e->b_render, 1650, 1103);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->b_add_sphere,1650, 0);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->b_add_plane,1650, 40);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->b_add_cylinder,1650, 80);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->b_add_cone,1650, 120);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->b_add_light,1650, 160);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->b_add_slice,1760, 0);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->sc_red,1650, 250);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->sc_green,1650, 290);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->sc_blue,1650, 330);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->in_color,1655, 370);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->show_color,1765, 371);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->la_brillance,1653, 435);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->sc_brillance,1730, 415);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->la_refraction,1653, 485);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->sc_refraction,1730, 465);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->la_transparency,1653, 535);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->sc_transparency,1730, 515);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->la_reflection,1653, 585);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->sc_reflection,1730, 565);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->la_bump_mapping,1653, 635);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->sc_bump_mapping,1730, 615);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->la_radius,1653, 675);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->sc_radius,1730, 665);

	g_signal_connect(e->b_render, "clicked", G_CALLBACK(render), e);
	g_signal_connect(e->b_add_sphere, "clicked", G_CALLBACK(add_sphere), e);
	g_signal_connect(e->b_add_plane, "clicked", G_CALLBACK(add_plane), e);
	g_signal_connect(e->b_add_cylinder, "clicked", G_CALLBACK(add_cylinder), e);
	g_signal_connect(e->b_add_cone, "clicked", G_CALLBACK(add_cone), e);
	g_signal_connect(e->b_add_light, "clicked", G_CALLBACK(add_light), e);
	g_signal_connect(e->b_add_slice, "clicked", G_CALLBACK(add_slice), e);
	g_signal_connect(e->sc_red, "value_changed", G_CALLBACK(color_change_red), e);
	g_signal_connect(e->sc_green, "value_changed", G_CALLBACK(color_change_green), e);
	g_signal_connect(e->sc_blue, "value_changed", G_CALLBACK(color_change_blue), e);
	g_signal_connect(e->sc_brillance, "value_changed", G_CALLBACK(brillance_change), e);
	g_signal_connect(e->sc_refraction, "value_changed", G_CALLBACK(refraction_change), e);
	g_signal_connect(e->sc_transparency, "value_changed", G_CALLBACK(transparency_change), e);
	g_signal_connect(e->sc_reflection, "value_changed", G_CALLBACK(reflection_change), e);
	g_signal_connect(e->sc_bump_mapping, "value_changed", G_CALLBACK(bump_mapping_change), e);
	g_signal_connect(e->sc_radius, "value_changed", G_CALLBACK(radius_change), e);
	g_signal_connect(e->in_color, "activate", G_CALLBACK(input_color_change), e);
	g_signal_connect(e->show_color, "draw", G_CALLBACK(do_cairo), e);
	g_signal_connect(e->show_color, "configure_event", G_CALLBACK(do_cairo_configure), e);
}

void init_env(t_env *e)
{
	init_vars(e);
	WIN = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	e->fixed = gtk_fixed_new();
	e->background = gtk_image_new_from_file("sprites/background.jpg");

	gtk_container_add(GTK_CONTAINER(WIN), e->fixed);
	gtk_window_set_default_size(GTK_WINDOW(WIN), WIDTH, HEIGHT);
	gtk_window_set_resizable (GTK_WINDOW(WIN), FALSE);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->background,0, 0);
	show_selected_obj(e);

	init_buttons(e);
	gtk_widget_add_events(GTK_WIDGET(WIN), GDK_SCROLL_MASK);
	g_signal_connect(G_OBJECT(WIN), "scroll_event", G_CALLBACK(scroll), e);
	g_signal_connect(G_OBJECT(WIN), "button_press_event", G_CALLBACK(click), e);
	add_obj(e, I_CAMERA);


	disable_widgets(e);

	refresh(e);

	gtk_main();

}
