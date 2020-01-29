/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 02:43:11 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/26 03:08:39 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static void		fill_c(t_point *c, t_point o, int r)
{
	c[0] = pt_new(o.y, o.x - 3 * r);
	c[1] = pt_new(o.y, o.x - r);
	c[2] = pt_new(o.y, o.x + r);
	c[3] = pt_new(o.y, o.x + 3 * r);
}

static void		fill_rot_c(t_point *rot_c, t_point *c, t_point o, int teta)
{
	rot_c[0] = pt_rot(o, c[0], teta);
	rot_c[1] = pt_rot(o, c[1], teta);
	rot_c[2] = pt_rot(o, c[2], teta);
	rot_c[3] = pt_rot(o, c[3], teta);
}

static void		ant_man(t_display *display, SDL_Color color,
		t_point o, int teta)
{
	t_point	c[4];
	t_point	rot_c[4];
	t_point	p[2];
	int		r;
	int		i;

	r = (display->block / 15) / 3;
	fill_c(c, o, r);
	fill_rot_c(rot_c, c, o, teta);
	p[0] = pt_rot(o, pt_new(c[0].y + 3 * r / 2, c[0].x - 3 * r / 2), teta);
	p[1] = pt_rot(o, pt_new(c[0].y - 3 * r / 2, c[0].x - 3 * r / 2), teta);
	sdl_line(display->env, sdl_rgb(0, 0, 0), rot_c[0], p[0]);
	sdl_line(display->env, sdl_rgb(0, 0, 0), rot_c[0], p[1]);
	sdl_disk(display->env, color, rot_c[0], r);
	sdl_circle(display->env, sdl_rgb(0, 0, 0), rot_c[0], r);
	i = 1;
	while (i < 4)
	{
		p[0] = pt_rot(o, pt_new(c[i].y - 2 * r, c[i].x), teta);
		p[1] = pt_rot(o, pt_new(c[i].y + 2 * r, c[i].x), teta);
		sdl_line(display->env, sdl_rgb(0, 0, 0), p[0], p[1]);
		sdl_disk(display->env, color, rot_c[i], r);
		sdl_circle(display->env, sdl_rgb(0, 0, 0), rot_c[i], r);
		i++;
	}
}

static t_point	coord_ant_interp(t_display *display, t_point p1, int next)
{
	t_point		coord_ant;
	t_infos		infos;
	t_point		p2;

	infos = display->infos;
	if (next != -1)
	{
		p2 = pt_new(display->offset.y +
				infos.rooms[next].coord.y * display->block,
				display->offset.x +
				infos.rooms[next].coord.x * display->block);
		coord_ant = pt_linterp(p1, p2, display->moment % STATE, STATE);
	}
	else
		coord_ant = pt_new(p1.y, p1.x);
	return (coord_ant);
}

void			draw_ant(t_display *display, t_infos infos, int x)
{
	t_point		coord_ant;
	SDL_Color	color;
	int			next;
	int			now;
	t_point		p1;

	next = -1;
	now = infos.tab_ants[x].tab_life[display->moment / STATE];
	color = color_macros(infos.tab_ants[x].color);
	p1 = pt_new(display->offset.y + infos.rooms[now].coord.y * display->block,
			display->offset.x + infos.rooms[now].coord.x * display->block);
	if (display->moment < STATE * infos.shots)
	{
		next = infos.tab_ants[x].tab_life[display->moment / STATE + 1];
		coord_ant = coord_ant_interp(display, p1, next);
	}
	else
		coord_ant = pt_new(p1.y, p1.x);
	ant_man(display, color, coord_ant,
			get_teta(display->infos, now, next));
}
