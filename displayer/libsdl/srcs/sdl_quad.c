/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_quad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:59:31 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:59:35 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

void			sdl_quad(t_sdlenv env, SDL_Color color, int n_pts, ...)
{
	va_list		args;
	t_point		*p;
	int			i;

	if (n_pts > 1)
	{
		i = 0;
		if (!(p = (t_point*)malloc(sizeof(t_point) * n_pts)))
			return ;
		va_start(args, n_pts);
		while (i < n_pts)
			p[i++] = va_arg(args, t_point);
		i = 0;
		while (++i < n_pts)
			sdl_line(env, color, p[i - 1], p[i]);
		sdl_line(env, color, p[0], p[n_pts - 1]);
		va_end(args);
		free(p);
	}
}
