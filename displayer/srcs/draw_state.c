/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 02:48:40 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/26 03:08:07 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static char		*str_msg(char *msg, int nbr)
{
	char		*str;
	char		*tmp;

	str = ft_strdup(msg);
	tmp = ft_itoa(nbr);
	ft_strcombin(&str, tmp);
	free(tmp);
	return (str);
}

static void		display_shots(t_display *display)
{
	SDL_Texture	*tex;
	SDL_Rect	pos;
	char		*str;

	str = str_msg("Shots: ", display->moment / STATE);
	tex = ttf_texture(display->env.render, display->font_text,
			str, sdl_rgb(0, 0, 0));
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	pos.y = HEIGHT / 10;
	pos.x = WIDTH / 30 + WIDTH / 10 - pos.w / 2;
	SDL_RenderCopy(display->env.render, tex, NULL, &pos);
	SDL_DestroyTexture(tex);
	free(str);
}

static void		display_ants(t_display *display)
{
	SDL_Texture	*tex;
	SDL_Rect	pos;
	char		*str;

	str = str_msg("Start: ",
			display->infos.start_end[display->moment / STATE].x);
	tex = ttf_texture(display->env.render, display->font_text,
			str, sdl_rgb(0, 0, 0));
	pos = rect_new(0, 0, HEIGHT / 20, WIDTH / 20);
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(display->env.render, tex, NULL, &pos);
	SDL_DestroyTexture(tex);
	str = str_msg("End: ", display->infos.start_end[display->moment / STATE].y);
	tex = ttf_texture(display->env.render, display->font_text,
			str, sdl_rgb(0, 0, 0));
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	pos.y = HEIGHT / 20;
	pos.x = WIDTH / 60 + WIDTH / 5 - pos.w;
	SDL_RenderCopy(display->env.render, tex, NULL, &pos);
	SDL_DestroyTexture(tex);
}

void			draw_state(t_display *display, t_infos infos)
{
	int			ant_state;
	int			i;

	i = 0;
	draw_scene(display);
	while (i < infos.ants)
	{
		ant_state = infos.tab_ants[i].tab_life[display->moment / STATE];
		if (ant_state != -1)
			draw_ant(display, infos, i);
		i++;
	}
	display_shots(display);
	display_ants(display);
	SDL_RenderPresent(display->env.render);
}
