/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rect_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:04:40 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:13:17 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

void			sdl_rect_e(t_sdlenv env, SDL_Color color, t_point a, t_point b)
{
	t_point		ab;
	t_point		ba;

	ab = pt_new(a.y, b.x);
	ba = pt_new(b.y, a.x);
	sdl_line(env, color, a, ab);
	sdl_line(env, color, ab, b);
	sdl_line(env, color, b, ba);
	sdl_line(env, color, ba, a);
}
