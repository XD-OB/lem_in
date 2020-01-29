/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:58:09 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:58:35 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

SDL_Texture		*ttf_texture(SDL_Renderer *render, TTF_Font *font,
									char *str, SDL_Color color)
{
	SDL_Surface	*surface;
	SDL_Texture	*text;

	surface = TTF_RenderText_Blended(font, str, color);
	text = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
	return (text);
}
