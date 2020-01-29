/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_fsquare_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:26:16 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:27:25 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

/*
**	color[0]: border		color[1]: inside
*/

void			sdl_fsquare(t_sdlenv env, SDL_Color color[2], t_point a, int l)
{
	t_point		p[3];
	SDL_Rect	rect;

	rect = rect_new(l, l, a.y, a.x);
	SDL_SetRenderDrawColor(env.render, color[1].r, color[1].g,
										color[1].b, color[1].a);
	SDL_RenderFillRect(env.render, &rect);
	p[0] = pt_new(a.y, a.x + l);
	p[1] = pt_new(a.y + l, a.x + l);
	p[2] = pt_new(a.y + l, a.x);
	sdl_line(env, color[0], a, p[0]);
	sdl_line(env, color[0], p[0], p[1]);
	sdl_line(env, color[0], p[1], p[2]);
	sdl_line(env, color[0], p[2], a);
}
