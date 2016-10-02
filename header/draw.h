#ifndef DRAW_H
# define DRAW_H

#define LINE(vi); dr_line(dr,vi);
#define CLINE(vi,color); dr_cline(dr,vi,color);

typedef struct 	s_draw
{
	char 		*filename;
}				t_draw;


#include "func.h"


t_draw 			*dr_make(char *filename);
void 			dr_line(t_draw *draw,char *str);
void 			dr_cline(t_draw *draw,char *str,char *color);

#endif