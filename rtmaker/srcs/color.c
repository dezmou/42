/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 20:48:02 by momartin          #+#    #+#             */
/*   Updated: 2017/01/10 17:48:39 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtmaker.h"

int		co_(int red, int green, int blue)
{
	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	return ((blue) + (red << 16) + (green << 8));
}

int		r_(int color)
{
	return (color >> 16);
}

int		g_(int color)
{
	return ((color & 0x00ff00) >> 8);
}

int		b_(int color)
{
	return ((color & 0x0000ff));
}
