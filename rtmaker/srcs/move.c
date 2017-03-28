#include "rtmaker.h"

void act_ori_pos(t_env *e, t_obj *obj)
{
	viewpos_by_vect(e, obj->pos);
	gtk_fixed_move(GTK_FIXED(e->fixed), obj->top_img, e->t_x - 15, e->t_y - 15 );
	gtk_fixed_move(GTK_FIXED(e->fixed), obj->front_img, e->f_x - 15, e->f_y - 15);
	gtk_fixed_move(GTK_FIXED(e->fixed), obj->left_img, e->l_x - 15, e->l_y - 15);

	gtk_fixed_move(GTK_FIXED(e->fixed), obj->top_vect, e->t_x - 15 + obj->ori.x, e->t_y - 15 - obj->ori.y );
	gtk_fixed_move(GTK_FIXED(e->fixed), obj->front_vect, e->f_x - 15 + obj->ori.x, e->f_y - 15 - obj->ori.z);
	gtk_fixed_move(GTK_FIXED(e->fixed), obj->left_vect, e->l_x - 15 + obj->ori.y, e->l_y - 15 - obj->ori.z);
}


void move_obj(t_env *e, t_obj *obj, int x, int y)
{
	vect_by_pos(&obj->pos, x, y);
	viewpos_by_vect(e, obj->pos);
	gtk_fixed_move(GTK_FIXED(e->fixed), obj->top_img, e->t_x - 15, e->t_y - 15 );
	gtk_fixed_move(GTK_FIXED(e->fixed), obj->front_img, e->f_x - 15, e->f_y - 15);
	gtk_fixed_move(GTK_FIXED(e->fixed), obj->left_img, e->l_x - 15, e->l_y - 15);

	gtk_fixed_move(GTK_FIXED(e->fixed), obj->top_vect, e->t_x - 15 + obj->ori.x, e->t_y - 15 - obj->ori.y );
	gtk_fixed_move(GTK_FIXED(e->fixed), obj->front_vect, e->f_x - 15 + obj->ori.x, e->f_y - 15 - obj->ori.z);
	gtk_fixed_move(GTK_FIXED(e->fixed), obj->left_vect, e->l_x - 15 + obj->ori.y, e->l_y - 15 - obj->ori.z);
}

void move_select_sprite(t_env *e)
{
	viewpos_by_vect(e, SOBJ.pos);
	gtk_fixed_move(GTK_FIXED(e->fixed), e->t_select_sprite, e->t_x - 20, e->t_y - 20);
	gtk_fixed_move(GTK_FIXED(e->fixed), e->l_select_sprite, e->l_x - 20, e->l_y - 20);
	gtk_fixed_move(GTK_FIXED(e->fixed), e->f_select_sprite, e->f_x - 20, e->f_y - 20);
}
