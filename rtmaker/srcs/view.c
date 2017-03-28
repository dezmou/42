#include "rtmaker.h"

void viewpos_by_pos(int *x, int *y)
{
	if (*x >= 813 && *x <= 1612 && *y > 0 && *y <= 602)
	{
		*x += -813;
		return ;
	}
	if (*x >= 813 && *x <= 1612 && *y > 615 && *y <= 1215)
	{
		*x += -813;
		*y += -615;
		return ;
	}
	if (*x >= 0 && *x <= 800 && *y >= 615 && *y <= 1215)
		*y += -615;
}

void viewpos_by_vect(t_env *e, t_vect v)
{
		e->t_x = (int)v.x + 1213;
		e->t_y = 300 - (int)v.y;
		e->f_x = (int)v.x + 1213;
		e->f_y = 915 - (int)v.z;
		e->l_x = (int)v.y + 400;
		e->l_y = 915 - (int)v.z;
}

int view_by_pos(int x, int y)
{
	if (x >= 813 && x <= 1612 && y > 0 && y <= 602)
		return (I_TOP);
	if (x >= 813 && x <= 1612 && y > 615 && y <= 1215)
		return (I_FRONT);
	if (x >= 0 && x <= 800 && y >= 615 && y <= 1215)
		return (I_LEFT);
	return (0);
}

void 	vect_by_pos(t_vect *v, int x, int y)
{
	if (view_by_pos(x, y) == I_TOP)
	{
		viewpos_by_pos(&x, &y);
		v->x = x - 400;
		v->y = 300 - y;
		return ;
	}
	if (view_by_pos(x, y) == I_FRONT)
	{
		viewpos_by_pos(&x, &y);
		v->x = x - 400;
		v->z = 300 - y;
		return ;
	}
	if (view_by_pos(x, y) == I_LEFT)
	{
		viewpos_by_pos(&x, &y);
		v->y = x - 400;
		v->z = 300 - y;
		return ;
	}
}
