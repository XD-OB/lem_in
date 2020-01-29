/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rect_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:16:07 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:17:07 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

void			sdl_rect_c(t_sdlenv env, SDL_Color color, SDL_Rect rect)
{
	t_point		p[4];

	p[0] = pt_new(rect.y - (rect.h / 2), rect.x - (rect.w / 2));
	p[1] = pt_new(rect.y - (rect.h / 2), rect.x + (rect.w / 2));
	p[2] = pt_new(rect.y + (rect.h / 2), rect.x + (rect.w / 2));
	p[3] = pt_new(rect.y + (rect.h / 2), rect.x - (rect.w / 2));
	sdl_line(env, color, p[0], p[1]);
	sdl_line(env, color, p[1], p[2]);
	sdl_line(env, color, p[2], p[3]);
	sdl_line(env, color, p[3], p[0]);
}
