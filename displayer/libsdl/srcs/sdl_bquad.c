/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_bquad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:01:46 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 21:12:19 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

static void		add_val(t_point *p, int i, int bold, int sign)
{
	if (p[i].x - p[i - 1].x)
	{
		if (sign)
			p[i].x += bold / 2;
		else
			p[i].x -= bold / 2;
	}
	if (p[i].y - p[i - 1].y)
	{
		if (sign)
			p[i].y += bold / 2;
		else
			p[i].y -= bold / 2;
	}
}

void			sdl_bquad(t_sdlenv env, SDL_Color color,
							int bold, int n_pts, ...)
{
	va_list		args;
	t_bline		bline;
	t_point		*p;
	int			i;

	if (n_pts < 2)
		return ;
	i = 0;
	if (!(p = (t_point*)malloc(sizeof(t_point) * n_pts)))
		return ;
	va_start(args, n_pts);
	while (i < n_pts)
		p[i++] = va_arg(args, t_point);
	i = 0;
	while (++i < n_pts)
	{
		add_val(p, i, bold, 1);
		bline = bline_new(p[i], p[i - 1], bold);
		sdl_bline(env, color, bline);
		add_val(p, i, bold, 0);
	}
	bline = bline_new(p[n_pts - 1], p[0], bold);
	sdl_bline(env, color, bline);
	va_end(args);
	free(p);
}
