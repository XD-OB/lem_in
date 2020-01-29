/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_square_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:38:41 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:38:59 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

void			sdl_square_c(t_sdlenv env, SDL_Color color, t_point c, int l)
{
	t_point		p[4];
	int			r;

	r = l / 2;
	p[0] = pt_new(c.y - r, c.x - r);
	p[1] = pt_new(c.y - r, c.x + r);
	p[2] = pt_new(c.y + r, c.x + r);
	p[3] = pt_new(c.y + r, c.x - r);
	sdl_line(env, color, p[0], p[1]);
	sdl_line(env, color, p[1], p[2]);
	sdl_line(env, color, p[2], p[3]);
	sdl_line(env, color, p[3], p[0]);
}
