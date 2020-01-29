/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:16:55 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/26 03:11:06 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static t_bline	affect_bline(t_display *display, int i, int j)
{
	t_room		*rooms;
	t_point		a;
	t_point		b;

	rooms = display->infos.rooms;
	a = pt_new(display->offset.y + rooms[i].coord.y * display->block,
			display->offset.x + rooms[i].coord.x * display->block);
	b = pt_new(display->offset.y + rooms[j].coord.y * display->block,
			display->offset.x + rooms[j].coord.x * display->block);
	return (bline_new(a, b, display->block / 8));
}

static void		draw_link(t_display *display, t_infos infos, int a, int b)
{
	SDL_Color	color;
	t_bline		bline;
	int			i;
	int			j;
	int			k;

	k = -1;
	i = -1;
	j = -1;
	while (++k < infos.v)
	{
		(infos.rooms[k].id == a) ? i = k : 0;
		(infos.rooms[k].id == b) ? j = k : 0;
		if (i != -1 && j != -1)
			break ;
	}
	bline = affect_bline(display, i, j);
	color = (display->infos.links[a][b] == 2 && display->trace) ?
		sdl_rgb(255, 177, 51) :
		color_macros(infos.color_paths);
	sdl_bline(display->env, color, bline);
}

static void		draw_edge(t_display *display)
{
	int			**matrix;
	int			size;
	int			i;
	int			j;

	i = 0;
	size = display->infos.v;
	matrix = display->infos.links;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (matrix[i][j])
				draw_link(display, display->infos, i, j);
			j++;
		}
		i++;
	}
}

void			draw_scene(t_display *display)
{
	SDL_Texture		*texture;
	SDL_Rect		rect;

	texture = img_texture(display->env.render, IMG_PATH);
	SDL_RenderCopy(display->env.render, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
	rect = rect_new(HEIGHT / 8, WIDTH / 5, HEIGHT / 30, WIDTH / 30);
	SDL_SetRenderDrawColor(display->env.render, 160, 160, 160, 255);
	SDL_RenderFillRect(display->env.render, &rect);
	draw_edge(display);
	draw_rooms(display);
}
