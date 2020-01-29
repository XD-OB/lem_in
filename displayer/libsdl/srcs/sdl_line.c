/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:59:56 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:49:39 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

static void		e_modif(double *e, t_point *delta, t_point *pt, int flag)
{
	if (flag == 1 || flag == -1)
	{
		*e += delta->x;
		pt->y += flag;
	}
	if (flag == 0)
	{
		*e += delta->y;
		pt->x++;
	}
}

static void		trace_pdy(t_sdlenv env, t_point pi, t_point pf)
{
	t_point		delta;
	double		e;

	delta.x = pf.x - pi.x;
	delta.y = pf.y - pi.y;
	if (delta.y < 0)
		delta.y *= -1;
	if (delta.x > delta.y)
	{
		e = delta.x / 2;
		while (pi.x < pf.x)
		{
			if ((e -= delta.y) < 0)
				e_modif(&e, &delta, &pi, 1);
			SDL_RenderDrawPoint(env.render, pi.x++, pi.y);
		}
		return ;
	}
	e = delta.y / 2;
	while (pi.y < pf.y)
	{
		if ((e -= delta.x) < 0)
			e_modif(&e, &delta, &pi, 0);
		SDL_RenderDrawPoint(env.render, pi.x, pi.y++);
	}
}

static void		trace_ndy(t_sdlenv env, t_point pi, t_point pf)
{
	t_point		delta;
	double		e;

	delta.x = pf.x - pi.x;
	delta.y = pf.y - pi.y;
	if (delta.y < 0)
		delta.y *= -1;
	if (delta.x > delta.y)
	{
		e = delta.x / 2;
		while (pi.x < pf.x)
		{
			if ((e -= delta.y) < 0)
				e_modif(&e, &delta, &pi, -1);
			SDL_RenderDrawPoint(env.render, pi.x++, pi.y);
		}
		return ;
	}
	e = delta.y / 2;
	while (pi.y > pf.y)
	{
		if ((e -= delta.x) < 0)
			e_modif(&e, &delta, &pi, 0);
		SDL_RenderDrawPoint(env.render, pi.x, pi.y--);
	}
}

void			sdl_line(t_sdlenv env, SDL_Color color, t_point pi, t_point pf)
{
	t_point		delta;

	SDL_SetRenderDrawColor(env.render, color.r, color.g, color.b, color.a);
	if (pi.x > pf.x)
		pt_swap(&pi, &pf);
	delta.x = pf.x - pi.x;
	delta.y = pf.y - pi.y;
	SDL_RenderDrawPoint(env.render, pi.x, pi.y);
	if (delta.y > 0)
		trace_pdy(env, pi, pf);
	else
		trace_ndy(env, pi, pf);
	SDL_RenderDrawPoint(env.render, pf.x, pf.y);
}
