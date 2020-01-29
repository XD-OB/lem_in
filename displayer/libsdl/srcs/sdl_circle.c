/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:05:19 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 21:03:00 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

static void		eight_coins(SDL_Renderer *render, t_point c, t_point p)
{
	SDL_RenderDrawPoint(render, c.x + p.x, c.y + p.y);
	SDL_RenderDrawPoint(render, c.x - p.x, c.y + p.y);
	SDL_RenderDrawPoint(render, c.x + p.x, c.y - p.y);
	SDL_RenderDrawPoint(render, c.x - p.x, c.y - p.y);
	SDL_RenderDrawPoint(render, c.x + p.y, c.y + p.x);
	SDL_RenderDrawPoint(render, c.x - p.y, c.y + p.x);
	SDL_RenderDrawPoint(render, c.x + p.y, c.y - p.x);
	SDL_RenderDrawPoint(render, c.x - p.y, c.y - p.x);
}

void			sdl_circle(t_sdlenv env, SDL_Color color, t_point c, int r)
{
	int			d;
	t_point		p;

	p.x = 0;
	p.y = r;
	d = r - 1;
	SDL_SetRenderDrawColor(env.render, color.r, color.g, color.b, color.a);
	while (p.y >= p.x)
	{
		eight_coins(env.render, c, p);
		if (d >= 2 * p.x)
			d -= 2 * p.x++ + 1;
		else if (d < 2 * (r - p.y))
			d += 2 * p.y-- - 1;
		else
			d += 2 * (p.y-- - p.x++ - 1);
	}
}
