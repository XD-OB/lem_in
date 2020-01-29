/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:01:25 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 19:47:12 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsdl.h"

SDL_Texture			*img_texture(SDL_Renderer *renderer, char *path)
{
	SDL_Surface		*tmp;
	SDL_Texture		*texture;

	tmp = IMG_Load(path);
	if (!tmp)
	{
		ft_dprintf(2, "Error: Can't Load the Image\n%s\n",
				IMG_GetError());
		return (NULL);
	}
	texture = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_FreeSurface(tmp);
	if (!texture)
		ft_dprintf(2, "Error: Can't Create the Texture\n %s\n",
				SDL_GetError());
	return (texture);
}
