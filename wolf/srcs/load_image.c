/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 22:00:14 by momartin          #+#    #+#             */
/*   Updated: 2017/02/03 22:00:16 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		xpm_first(t_img_reader *red)
{
	char **tmp;

	if ((red->line)[0] == '"')
	{
		tmp = ft_strsplit(red->line, ' ');
		tmp[0][0] = '0';
		red->width = ft_atoi(tmp[0]);
		red->height = ft_atoi(tmp[1]);
		red->img = init_img(red->width, red->height);
		red->rendu = 1;
		free_splited_str(tmp);
	}
}

static void		xpm_colors(t_img_reader *red)
{
	char	**tmp;
	char	zouze[3];

	tmp = ft_strsplit(red->line, ' ');
	zouze[0] = (red->line)[1];
	zouze[1] = (red->line)[2];
	zouze[2] = 0;
	tmp[2][0] = '0';
	tmp[2][7] = 0;
	red->toli[red->indextoli].color = strtol(tmp[2], NULL, 16);
	ft_strcpy(red->toli[red->indextoli].str, zouze);
	free_splited_str(tmp);
	red->indextoli++;
}

static int		xpm_get_color_str(t_img_reader *red, char *t)
{
	int i;

	i = -1;
	while (++i <= 256)
	{
		if (t[0] == red->toli[i].str[0] && t[1] == red->toli[i].str[1])
			return (red->toli[i].color);
	}
	return (0);
}

static void		xpm_pixels(t_img_reader *red)
{
	int		x;
	int		i;
	int		s;
	char	*t;

	if ((red->line)[0] == '}')
		return ;
	t = malloc(3);
	i = 0;
	x = 0;
	s = 0;
	t[2] = 0;
	while (red->line[++i] != '"')
	{
		t[s] = red->line[i];
		s++;
		if (s == 2)
		{
			red->img->tab[red->index_h][x] = xpm_get_color_str(red, t);
			s = 0;
			x++;
		}
	}
	free(t);
	red->index_h++;
}

t_img			*load_image(char *filename)
{
	t_img_reader red;

	red.fd = open(filename, O_RDONLY);
	red.rendu = 0;
	red.indextoli = 0;
	red.index_h = 0;
	while (get_next_line(red.fd, &red.line))
	{
		if (ft_strstr(red.line, "/* pixels */"))
		{
			red.rendu = 2;
			free(red.line);
			continue ;
		}
		if (red.rendu == 0)
			xpm_first(&red);
		if (red.rendu == 1)
			xpm_colors(&red);
		if (red.rendu == 2)
			xpm_pixels(&red);
		free(red.line);
	}
	return (red.img);
}
