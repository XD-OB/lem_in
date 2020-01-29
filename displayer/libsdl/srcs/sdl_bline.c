/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_bline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:03:24 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 21:03:25 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

static void		bline_delta_y(t_sdlenv env, SDL_Color color, t_bline bline)
{
	t_point		pi_tmp;
	t_point		pf_tmp;
	int			minus;
	int			i;

	i = 0;
	minus = bline.bold / 2 - 1;
	pi_tmp = pt_new(bline.pi.y, bline.pi.x - minus);
	pf_tmp = pt_new(bline.pf.y, bline.pf.x - minus);
	while (i < bline.bold)
	{
		sdl_line(env, color, pi_tmp, pf_tmp);
		pi_tmp.x++;
		pf_tmp.x++;
		i++;
	}
}

static void		bline_delta_x(t_sdlenv env, SDL_Color color, t_bline bline)
{
	t_point		pi_tmp;
	t_point		pf_tmp;
	int			minus;
	int			i;

	i = 0;
	minus = bline.bold / 2 - 1;
	pi_tmp = pt_new(bline.pi.y - minus, bline.pi.x);
	pf_tmp = pt_new(bline.pf.y - minus, bline.pf.x);
	while (i < bline.bold)
	{
		sdl_line(env, color, pi_tmp, pf_tmp);
		pi_tmp.y++;
		pf_tmp.y++;
		i++;
	}
}

void			sdl_bline(t_sdlenv env, SDL_Color color, t_bline bline)
{
	t_point		delta;

	if (bline.pi.x > bline.pf.x)
		pt_swap(&(bline.pi), &(bline.pf));
	else if (bline.pi.y > bline.pf.y)
		pt_swap(&(bline.pi), &(bline.pf));
	delta.x = bline.pf.x - bline.pi.x;
	delta.y = bline.pf.y - bline.pi.y;
	if (delta.x > delta.y)
		bline_delta_x(env, color, bline);
	else
		bline_delta_y(env, color, bline);
}
