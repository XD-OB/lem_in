/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:16:40 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/25 06:14:36 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void			init_infos(t_infos *infos)
{
	infos->debug = 0;
	infos->v = 0;
	infos->ants = 0;
	infos->shots = 0;
	infos->input = NULL;
	infos->tab_hash = NULL;
	infos->rooms = NULL;
	infos->links = NULL;
	infos->tab_ants = NULL;
	infos->color_paths = L_WHITE;
}

void			init_vars_display(t_display *display)
{
	display->start_ants = display->infos.ants;
	display->end_ants = 0;
	display->moment = 0;
	display->pause = 1;
	display->pass = 1;
	display->trace = 0;
	display->f = 0;
}

static void		fill_frames(int *frames)
{
	frames[0] = 1 / 1000000;
	frames[1] = 1;
	frames[2] = 20;
	frames[3] = 200;
}

int				init_display(t_display *display)
{
	sdlenv_init(&(display->env), 1, 1, 1);
	sdl_init(display->env);
	if (!sdlenv_fill(&(display->env), TITLE, HEIGHT, WIDTH))
		return (0);
	load_music(&(display->env), MUSIC_PATH);
	fill_frames(display->frame);
	display->font_text = TTF_OpenFont(FONT_TYPE_TXT, FONT_SIZE_TXT);
	display->mute = -1;
	display->block = WIDTH / 10;
	display->offset = pt_new(400, 200);
	init_vars_display(display);
	return (1);
}
