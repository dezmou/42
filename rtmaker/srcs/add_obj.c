#include "rtmaker.h"

void add_obj(t_env *e, int type)
{
	e->nbrobjs += 1;
	OBJ[e->nbrobjs].pos.x = 0;
	OBJ[e->nbrobjs].pos.y = 0;
	OBJ[e->nbrobjs].pos.z = 0;
	OBJ[e->nbrobjs].ori.x = 0;
	OBJ[e->nbrobjs].ori.y = 80;
	OBJ[e->nbrobjs].ori.z = 0;
	OBJ[e->nbrobjs].type = type;
	OBJ[e->nbrobjs].slice_index = 0;
	OBJ[e->nbrobjs].mat.red = 100;
	OBJ[e->nbrobjs].mat.green = 100;
	OBJ[e->nbrobjs].mat.blue = 100;
	if (type == I_LIGHT)
	{
		OBJ[e->nbrobjs].mat.red = 255;
		OBJ[e->nbrobjs].mat.green = 255;
		OBJ[e->nbrobjs].mat.blue = 255;
	}
	OBJ[e->nbrobjs].mat.transparency = 0;
	OBJ[e->nbrobjs].mat.brillance = 0;
	OBJ[e->nbrobjs].mat.refraction = 0;
	OBJ[e->nbrobjs].mat.reflection = 0;
	OBJ[e->nbrobjs].mat.bump_mapping = 0;
	if (type == I_SPHERE || type == I_CONE || type == I_CYLINDER)
		OBJ[e->nbrobjs].radius = 25;
	else
		OBJ[e->nbrobjs].radius = 0;

	show_obj(e, &OBJ[e->nbrobjs]);
	e->selected_obj = e->nbrobjs;
	select_obj_act_material_buttons(e);
	disable_widgets(e);
	refresh(e);
}

void add_sphere(GTW *widget, t_env *e)
{
	add_obj(e, I_SPHERE);
}

void add_plane(GTW *widget, t_env *e)
{
	add_obj(e, I_PLANE);
}

void add_cylinder(GTW *widget, t_env *e)
{
	add_obj(e ,I_CYLINDER);
}

void add_cone(GTW *widget, t_env *e)
{
	add_obj(e, I_CONE);
}

void add_light(GTW *widget, t_env *e)
{
	add_obj(e, I_LIGHT);
}

void add_slice(GTW *widget, t_env *e)
{
	add_obj(e, I_SLICE);
	e->apply_slice_nbr = e->selected_obj;
}

void select_obj_act_material_buttons(t_env *e)
{

	gtk_range_set_value(GTK_RANGE(e->sc_blue), (double)SOBJ.mat.blue);
	gtk_range_set_value(GTK_RANGE(e->sc_green),(double)SOBJ.mat.green);
	gtk_range_set_value(GTK_RANGE(e->sc_red), (double)SOBJ.mat.red);
	gtk_range_set_value(GTK_RANGE(e->sc_transparency), (double)SOBJ.mat.transparency);
	gtk_range_set_value(GTK_RANGE(e->sc_brillance), (double)SOBJ.mat.brillance);
	gtk_range_set_value(GTK_RANGE(e->sc_refraction), (double)SOBJ.mat.refraction);
	gtk_range_set_value(GTK_RANGE(e->sc_reflection), (double)SOBJ.mat.reflection);
	gtk_range_set_value(GTK_RANGE(e->sc_bump_mapping), (double)SOBJ.mat.bump_mapping);
	gtk_range_set_value(GTK_RANGE(e->sc_radius), (double)SOBJ.radius);
	refresh(e);
}

void select_obj(t_env *e, int x, int y)
{
	int i;
	int score;

	i = -1;
	score = 99999;
	while (++i <= e->nbrobjs)
	{
		if (view_by_pos(x, y) == I_TOP)
		{
			viewpos_by_vect(e, e->objs[i].pos);
			if (score > abs(x - e->t_x) + abs(y - e->t_y))
			{
				e->selected_obj = i;
				score = abs(x - e->t_x) + abs(y - e->t_y);
			}
		}
		if (view_by_pos(x, y) == I_FRONT)
		{
			viewpos_by_vect(e, e->objs[i].pos);
			if (score > abs(x - e->f_x) + abs(y - e->f_y))
			{
				e->selected_obj = i;
				score = abs(x - e->f_x) + abs(y - e->f_y);
			}
		}
		if (view_by_pos(x, y) == I_LEFT)
		{
			viewpos_by_vect(e, e->objs[i].pos);
			if (score > abs(x - e->l_x) + abs(y - e->l_y))
			{
				e->selected_obj = i;
				score = abs(x - e->l_x) + abs(y - e->l_y);
			}
		}
	}
	select_obj_act_material_buttons(e);
	if (e->apply_slice_nbr != 0)
	{
		OBJ[e->apply_slice_nbr].slice_index = e->selected_obj;
		e->apply_slice_nbr = 0;
		printf("Sliced !\n");
	}
	disable_widgets(e);

}
