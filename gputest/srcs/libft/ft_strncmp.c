/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 06:57:07 by momartin          #+#    #+#             */
/*   Updated: 2016/11/07 15:35:34 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < 0)
				return (s2[i] - s1[i]);
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
