/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_fsquare_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:34:48 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 21:02:06 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

/*
**	color[0]: border		color[1]: inside
*/

void			sdl_fsquare_c(t_sdlenv env, SDL_Color color[2],
								t_point a, int l)
{
	t_point		p[4];
	SDL_Rect	rect;
	int			r;

	r = l / 2;
	p[0] = pt_new(a.y - r, a.x - r);
	p[1] = pt_new(a.y - r, a.x + r);
	p[2] = pt_new(a.y + r, a.x + r);
	p[3] = pt_new(a.y + r, a.x - r);
	rect = rect_new(l, l, p[0].y, p[0].x);
	SDL_SetRenderDrawColor(env.render, color[1].r, color[1].g,
									color[1].b, color[1].a);
	SDL_RenderFillRect(env.render, &rect);
	sdl_line(env, color[0], p[0], p[1]);
	sdl_line(env, color[0], p[1], p[2]);
	sdl_line(env, color[0], p[2], p[3]);
	sdl_line(env, color[0], p[3], p[0]);
}
