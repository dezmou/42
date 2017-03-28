#include "rtmaker.h"

void render_slices(FILE *fi, t_env *e, int index)
{
	int i;

	i = -1;
	while (++i <= e->nbrobjs)
		if (OBJ[i].type == I_SLICE && OBJ[i].slice_index == index)
		{
			fprintf(fi, " SLICE %d %d %d  %d %d %d", (int)OBJ[i].pos.x, (int)OBJ[i].pos.y, (int)OBJ[i].pos.z, (int)OBJ[i].ori.x, (int)OBJ[i].ori.y, (int)OBJ[i].ori.z);
		}
}
/*
void render_material(FILE *fi, t_ev *e, int index)
{
	//fprintf(fi, "MATERIAL %f %f %f %f %f %f %f %f ", IOBJM.red/255,  )
	(float)e->objs[i].mat.red/255, (float)e->objs[i].mat.green/255, (float)e->objs[i].mat.blue/255, (float)e->objs[i].mat.reflection/100 ,(float)e->objs[i].mat.brillance/100,(float)e->objs[i].mat.bump_mapping/100 ,(float)e->objs[i].mat.refraction/100, (float)e->objs[i].mat.transparency/100, e->objs[i].radius);
}
*/

void write_file(t_env *e)
{
	FILE *fi = fopen("confmaker", "w");
	int i;
		printf("%d, %d, %d\n", (int)CAM.ori.x, (int)CAM.ori.y, (int)CAM.ori.z);
	fprintf(fi,"CAMERA %d %d %d ORIENTATION %d %d %d\n", (int)CAM.pos.x, (int)CAM.pos.y, -(int)CAM.pos.z, (int)CAM.ori.x, (int)CAM.ori.y, -(int)CAM.ori.z);
	i = 0;
	while (++i <= e->nbrobjs)
	{
		if (e->objs[i].type == I_SPHERE)
		{
			fprintf(fi, "SPHERE %d %d %d MATERIAL %f %f %f %f %f %f %f %f RADIUS %d", (int)e->objs[i].pos.x, (int)e->objs[i].pos.y, -(int)e->objs[i].pos.z, (float)e->objs[i].mat.red/255, (float)e->objs[i].mat.green/255, (float)e->objs[i].mat.blue/255, (float)e->objs[i].mat.reflection/100 ,(float)e->objs[i].mat.brillance/100,(float)e->objs[i].mat.bump_mapping/100 ,(float)e->objs[i].mat.refraction/100, (float)e->objs[i].mat.transparency/100, e->objs[i].radius);
			render_slices(fi, e, i);
			fprintf(fi, "\n");
			continue ;
		}
		if (e->objs[i].type == I_LIGHT)
		{
			fprintf(fi, "LIGHT %d %d %d INTENSITY %f %f %f\n", (int)e->objs[i].pos.x, (int)e->objs[i].pos.y, (int)e->objs[i].pos.z, (float)e->objs[i].mat.red/255, (float)e->objs[i].mat.green/255, (float)e->objs[i].mat.blue/255 );
			continue ;
		}
		if (e->objs[i].type == I_PLANE)
		{
			fprintf(fi, "PLANE %d %d %d MATERIAL 1 0 0 0 0 0 0 0 ORIENTATION %d %d %d", (int)e->objs[i].pos.x, (int)e->objs[i].pos.y, -(int)e->objs[i].pos.z, (int)e->objs[i].ori.x, (int)e->objs[i].ori.y, (int)e->objs[i].ori.z);
			render_slices(fi, e, i);
			fprintf(fi, "\n");
			continue ;
		}
		if (e->objs[i].type == I_CYLINDER)
		{
			fprintf(fi, "CYLINDER %d %d %d MATERIAL 1 0 0 0 0 0 0 ORIENTATION %d %d %d RADIUS 50", (int)e->objs[i].pos.x, (int)e->objs[i].pos.y, -(int)e->objs[i].pos.z, (int)e->objs[i].ori.x, (int)e->objs[i].ori.y, (int)e->objs[i].ori.z);
			render_slices(fi, e, i);
			fprintf(fi, "\n");
			continue ;
		}
		if (e->objs[i].type == I_CONE)
		{
			fprintf(fi, "CONE %d %d %d MATERIAL 1 0 0 0 0 0 0 0  ORIENTATION %d %d %d ANGLE 10", (int)e->objs[i].pos.x, (int)e->objs[i].pos.y, -(int)e->objs[i].pos.z, (int)e->objs[i].ori.x, (int)e->objs[i].ori.y, (int)e->objs[i].ori.z);
			render_slices(fi, e, i);
			fprintf(fi, "\n");
			continue ;
		}
	}
	fclose(fi);
}

void render(GTW *widget, t_env *e)
{
	write_file(e);
	system("./RTv1 confmaker");
	e->rendu = gtk_image_new_from_file("out.bmp");
	gtk_fixed_put(GTK_FIXED(e->fixed), e->rendu, 0, 0);
	refresh(e);
}
