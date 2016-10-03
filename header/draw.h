#ifndef DRAW_H
# define DRAW_H
#define MKDRAW t_draw *dr = dr_make("file.html");
#define LINE(vi) dr_line(dr,vi);
#define CLINE(vi,color) dr_cline(dr,vi,color);
#define LINE_INT(intt) dr_line_int(dr,intt);
#define MKGRAPH dr_mkgraph(dr);
#define ADDGRAPH(value) dr_graph(dr,value);
#define ENDGRAPH dr_endgraph(dr);
typedef struct 	s_draw
{
	char 		*filename;
	int 		graph_max;
	int 		graph_x;
}				t_draw;


#include "func.h"
void 			dr_endgraph(t_draw *draw);
void 			dr_graph(t_draw *draw ,int value);
void 			dr_mkgraph(t_draw *draw);
void 			dr_line_int(t_draw *draw,int nbr);
t_draw 			*dr_make(char *filename);
void 			dr_line(t_draw *draw,char *str);
void 			dr_cline(t_draw *draw,char *str,char *color);

#endif