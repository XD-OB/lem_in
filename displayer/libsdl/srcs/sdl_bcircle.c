/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_bcircle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:05:19 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:51:29 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

void			sdl_bcircle(t_sdlenv env, SDL_Color color, t_bcircle bcircle)
{
	int	bold;
	int	r;
	int	i;

	i = 0;
	bold = bcircle.bold;
	r = bcircle.r - bold;
	while (i < bold)
	{
		sdl_circle(env, color, bcircle.c, r);
		r++;
		i++;
	}
}
