/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:59:46 by momartin          #+#    #+#             */
/*   Updated: 2017/01/11 19:59:48 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTUGE_H
# define TESTUGE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include <SDl2/SDL.h>

# define WIDTH 2000
# define HEIGHT 1200

# define WIN e->window
# define SRENDER e->srender
# define RENDU e->rendu
# define TEXTURE e->texture

typedef struct	s_env
{
	SDL_Window      *window;
	SDL_Renderer 	*srender;
	SDL_Surface 	*rendu;
	SDL_Texture 	*texture;

}				t_env;


#endif
