/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:59:46 by momartin          #+#    #+#             */
/*   Updated: 2017/01/28 17:57:36 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define PRINT 0
# define LINE e->line
# define NBPL e->nbrplayer
# define WIDTH e->width
# define HEIGHT e->height
# define PHEIGHT e->p_height
# define PWIDTH e->p_width
# define MAP e->map
# define PIECE e->piece
# define CLN e->cleaner
# define PPIECE printpiece(e);
# define PMAP printmap(e);
# define DEB e->debug

typedef struct	s_cleaner
{
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
}				t_cleaner;

typedef struct	s_env
{
	char		over;
	char		*line;
	char		nbrplayer;
	char		map[400][400];
	char		map_is_malloc;
	char		piece[400][400];
	char		tmppiece[400][400];
	int			width;
	int			height;
	int			p_width;
	int			p_height;
	t_cleaner	cleaner;
	int			res;
	int			min_score;
	int			nbrgame;
}				t_env;

void			get_infos(t_env *e);
void			init(t_env *e);
void			reinit(t_env *e);
void			free_splited_str(char **str);
void			get_piece(t_env *e);
void			clean_piece(t_env *e, int neox, int neoy);
void			set_piece_clean(t_env *e);
void			get_map(t_env *e);
void			get_nbrplayer(t_env *e);
void			apply_get_map(t_env *e);
void			get_infos(t_env *e);
void			apply_engine(t_env *e, int x, int y);
void			printmap(t_env *e);
void			apply_map_x(t_env *e);
void			push(t_env *e, int x, int y);
#endif
