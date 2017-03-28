#include "rtmaker.h"

void enable_all_widgets(t_env *e)
{
	gtk_widget_set_sensitive(e->in_color, TRUE);
	gtk_widget_set_sensitive(e->sc_brillance, TRUE);
	gtk_widget_set_sensitive(e->sc_refraction, TRUE);
	gtk_widget_set_sensitive(e->sc_reflection, TRUE);
	gtk_widget_set_sensitive(e->sc_transparency, TRUE);
	gtk_widget_set_sensitive(e->sc_bump_mapping, TRUE);
	gtk_widget_set_sensitive(e->sc_red, TRUE);
	gtk_widget_set_sensitive(e->sc_green, TRUE);
	gtk_widget_set_sensitive(e->sc_radius, TRUE);
	gtk_widget_set_sensitive(e->sc_blue, TRUE);
	gtk_widget_set_sensitive(e->sc_radius, TRUE);
}

void disable_widgets(t_env *e)
{
	enable_all_widgets(e);
	if (SOBJ.type == I_CAMERA || SOBJ.type == I_LIGHT || SOBJ.type == I_SLICE)
	{
		gtk_widget_set_sensitive(e->sc_brillance, FALSE);
		gtk_widget_set_sensitive(e->sc_refraction, FALSE);
		gtk_widget_set_sensitive(e->sc_reflection, FALSE);
		gtk_widget_set_sensitive(e->sc_transparency, FALSE);
		gtk_widget_set_sensitive(e->sc_bump_mapping, FALSE);
		gtk_widget_set_sensitive(e->sc_radius, FALSE);
	}
	if (SOBJ.type == I_CAMERA || SOBJ.type == I_SLICE)
	{
		gtk_widget_set_sensitive(e->in_color, FALSE);
		gtk_widget_set_sensitive(e->sc_red, FALSE);
		gtk_widget_set_sensitive(e->sc_green, FALSE);
		gtk_widget_set_sensitive(e->sc_blue, FALSE);
	}
	if (SOBJ.type != I_SPHERE && SOBJ.type != I_CYLINDER && SOBJ.type != I_CONE)
		gtk_widget_set_sensitive(e->sc_radius, FALSE);
}


void 	show_obj(t_env *e, t_obj *obj)//init sprites
{
	viewpos_by_vect(e, obj->pos);
	obj->top_img = gtk_image_new_from_file(e->sprites[obj->type]);
	gtk_fixed_put(GTK_FIXED(e->fixed),obj->top_img ,e->t_x - 15, e->t_y - 15);
	obj->front_img = gtk_image_new_from_file(e->sprites[obj->type]);
	gtk_fixed_put(GTK_FIXED(e->fixed),obj->front_img ,e->f_x - 15, e->f_y - 15);
	obj->left_img = gtk_image_new_from_file(e->sprites[obj->type]);
	gtk_fixed_put(GTK_FIXED(e->fixed),obj->left_img ,e->l_x - 15, e->l_y - 15);
	obj->top_vect = gtk_image_new_from_file(e->sprites[I_CIBLE]);
	gtk_fixed_put(GTK_FIXED(e->fixed),obj->top_vect ,e->t_x - 15 + obj->ori.x, e->t_y - 15 - obj->ori.y);
	obj->front_vect = gtk_image_new_from_file(e->sprites[I_CIBLE]);
	gtk_fixed_put(GTK_FIXED(e->fixed),obj->front_vect ,e->f_x - 15 + obj->ori.x, e->f_y - 15 - obj->ori.z);
	obj->left_vect = gtk_image_new_from_file(e->sprites[I_CIBLE]);
	gtk_fixed_put(GTK_FIXED(e->fixed),obj->left_vect ,e->l_x - 15 + obj->ori.y, e->l_y - 15 - obj->ori.z);

}

void show_selected_obj(t_env *e)//init sprite
{
	e->t_select_sprite = gtk_image_new_from_file(e->sprites[I_SELECT]);
	e->l_select_sprite = gtk_image_new_from_file(e->sprites[I_SELECT]);
	e->f_select_sprite = gtk_image_new_from_file(e->sprites[I_SELECT]);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->f_select_sprite, 0, 0);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->l_select_sprite, 0, 0);
	gtk_fixed_put(GTK_FIXED(e->fixed), e->t_select_sprite, 0, 0);
}

void hide_cible(t_env *e)
{
	int i;

	i = -1;
	while (++i <= e->nbrobjs)
	{
		if (i != e->selected_obj)
		{
			gtk_widget_hide(e->objs[i].top_vect);
			gtk_widget_hide(e->objs[i].front_vect);
			gtk_widget_hide(e->objs[i].left_vect);
		}
		else
		{
			gtk_widget_show(e->objs[i].top_vect);
			gtk_widget_show(e->objs[i].front_vect);
			gtk_widget_show(e->objs[i].left_vect);
		}
	}
}
