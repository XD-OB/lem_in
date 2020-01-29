/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_square_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:24:15 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:25:21 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

void			sdl_square_a(t_sdlenv env, SDL_Color color, t_point a, int l)
{
	t_point		p[3];

	p[0] = pt_new(a.y, a.x + l);
	p[1] = pt_new(a.y + l, a.x + l);
	p[2] = pt_new(a.y + l, a.x);
	sdl_line(env, color, a, p[0]);
	sdl_line(env, color, p[0], p[1]);
	sdl_line(env, color, p[1], p[2]);
	sdl_line(env, color, p[2], a);
}
