/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:09:34 by jclerc            #+#    #+#             */
/*   Updated: 2016/02/23 17:32:50 by jclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

static t_gnl	*gnl_lstnew(int fd)
{
	t_gnl *dline;

	dline = (t_gnl*)malloc(sizeof(*dline));
	dline->content = ft_strnew(1);
	dline->byt = 1;
	dline->fd = fd;
	dline->next = NULL;
	return (dline);
}

static t_gnl	*gnl_find_element(t_gnl *aline, int fd)
{
	t_gnl *dline;

	while (aline)
	{
		if (aline->fd == fd)
			break ;
		if (aline->next == NULL)
		{
			dline = gnl_lstnew(fd);
			aline->next = dline;
			return (dline);
		}
		aline = aline->next;
	}
	return (aline);
}

static int		gnl_n(t_gnl **dline, char **line)
{
	char *tmp;
	char *tmp1;

	if ((tmp = ft_strchr((*dline)->content, '\n')) != NULL)
	{
		*tmp = '\0';
		*line = ft_strdup((*dline)->content);
		tmp1 = (*dline)->content;
		(*dline)->content = ft_strdup(tmp + 1);
		ft_strdel(&tmp1);
		return (1);
	}
	return (0);
}

static int		gnl_read(t_gnl **dline, char **line)
{
	char buff[BUFF_SIZE + 1];
	char *tmp;

	while (((*dline)->byt = read((*dline)->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[(*dline)->byt] = '\0';
		tmp = ft_strjoin((*dline)->content, buff);
		ft_strdel(&(*dline)->content);
		(*dline)->content = tmp;
		if (gnl_n(dline, line) == 1)
			return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*aline;
	t_gnl			*dline;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (!aline)
		aline = gnl_lstnew(fd);
	dline = gnl_find_element(aline, fd);
	if ((gnl_read(&dline, line) == 1))
		return (1);
	if (dline->byt == -1)
		return (-1);
	if (ft_strlen(dline->content) == 0)
	{
		ft_strdel(&(aline->content));
		free(aline);
		aline = NULL;
		return (0);
	}
	if (gnl_n(&dline, line) != 1)
	{
		*line = ft_strdup(dline->content);
		ft_strclr(dline->content);
	}
	return (1);
}
