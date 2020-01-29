/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_brect_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:06:56 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 21:02:29 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

void			sdl_brect_e(t_sdlenv env, SDL_Color color, t_bline info)
{
	t_bline		bline;
	t_point		a;
	t_point		b;

	a = pt_new(info.pi.y, info.pf.x);
	b = pt_new(info.pf.y, info.pi.x);
	bline = bline_new(info.pi, a, info.bold);
	sdl_bline(env, color, bline);
	bline = bline_new(a, info.pf, info.bold);
	sdl_bline(env, color, bline);
	bline = bline_new(info.pf, b, info.bold);
	sdl_bline(env, color, bline);
	bline = bline_new(b, info.pi, info.bold);
	sdl_bline(env, color, bline);
}
