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
	write(fd,"<br/>\n",6);
	close(fd);
}
