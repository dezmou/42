/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:59:31 by momartin          #+#    #+#             */
/*   Updated: 2017/01/11 19:59:32 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testuge.h"

void    init_display(t_env *e)
{

	SDL_Init(SDL_INIT_VIDEO);
    WIN = SDL_CreateWindow("RT Maker", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,0);
	SRENDER = SDL_CreateRenderer(WIN, -1, 0);
	RENDU = SDL_LoadBMP("out.bmp");
	TEXTURE = SDL_CreateTexture(SRENDER, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
}

void draw(t_env *e, int x, int y)
{

}

void pack();

int main(int argc, char** argv)
{
	t_env e;

	init_display(&e);
	SDL_Delay(3000);

	return 0;
}
