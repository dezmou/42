/*
DRAW sert a afficher des truc dans un fichier html par ce que c'est 
marrant et fuck you, tu peux meme ecrire en couleur avec dr_cline; 
*/


#include "draw.h"

t_draw 		*dr_make(char *filename)
{
	char begin[1000];
	int fd;
	int res;
	
	fd = open("draw/fightml/begin.html",O_RDONLY);
	res = read(fd,begin,sizeof(char)*1000);
	close(fd);
	t_draw *final;
	final = (t_draw *)malloc(sizeof(t_draw));
	final->filename = ft_strdup(filename);
	fclose(fopen(filename, "w"));
	fd = open(filename,O_CREAT | O_RDWR,0777);
	write(fd,begin,ft_strlen(begin));
	close(fd);
	return final;
}

void 		dr_line(t_draw *draw,char *str)
{
	int fd;
	fd = open(draw->filename,O_APPEND | O_RDWR);
	write(fd,str,ft_strlen(str));
	write(fd,"<br/>\n",6);
	close(fd);
}

void 		dr_cline(t_draw *draw,char *str,char *color)
{
	int fd;
	fd = open(draw->filename,O_APPEND | O_RDWR);
	write(fd,"<span style='color:",19);
	write(fd,color,ft_strlen(color));
	write(fd,";'>",3);
	write(fd,str,ft_strlen(str));
	write(fd,"</span>",7);
	write(fd,"<br/>\n",6);
	close(fd);
}

void 		dr_line_int(t_draw *draw,int nbr)
{
	int fd;
	fd = open(draw->filename,O_APPEND | O_RDWR);
	w_putnbr(nbr);
	write(fd,"<br/>\n",6);
	close(fd);
}


void 		dr_mkgraph(t_draw *draw)
{
	int fd;
	
	draw->graph_x = 0;
	fd = open(draw->filename,O_APPEND | O_RDWR);
	write(fd,"<svg width=5000 height=500>\n",28);
	close(fd);
}
void 		dr_graph(t_draw *draw ,int value)
{
	int fd;
	
	int y = (130-value);
	fd = open(draw->filename,O_APPEND | O_RDWR);

	write(fd,"<rect x=",8);
	w_putnbr(draw->graph_x);
	write(fd," y=",3);
	w_putnbr(y);
	write(fd," width=10 height=",17);
	w_putnbr(value);
	write(fd," style=fill:blue />\n",20);
	draw->graph_x += 11;
	close(fd);

}
void 		dr_endgraph(t_draw *draw)
{
	int fd;
	fd = open(draw->filename,O_APPEND | O_RDWR);
	write(fd,"</svg>",6);

	close(fd);
}