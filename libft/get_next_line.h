/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:05:45 by jclerc            #+#    #+#             */
/*   Updated: 2016/09/12 16:35:06 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# define BUFF_SIZE 1

typedef struct	s_gnl
{
	char			*content;
	int				byt;
	int				fd;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(int const fd, char **line);
#endif
