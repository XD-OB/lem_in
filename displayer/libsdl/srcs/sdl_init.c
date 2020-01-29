/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:42:53 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 19:42:56 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsdl.h"

static int			error_manager(t_sdlenv env, int type)
{
	if (type == 0)
		ft_dprintf(2, "Error will Initialize the SDL: %s\n",
				SDL_GetError());
	else if (type == 1)
	{
		ft_dprintf(2, "Error will Initialize the SDL_Image: %s\n",
				IMG_GetError());
		SDL_Quit();
	}
	else if (type == 2)
	{
		ft_dprintf(2, "Error will Initialize the SDL_TTF: %s\n",
				TTF_GetError());
		(env.img) ? IMG_Quit() : 0;
		SDL_Quit();
	}
	else if (type == 3)
	{
		ft_dprintf(2, "Error will Opening Audio: %s\n",
				Mix_GetError());
		(env.img) ? IMG_Quit() : 0;
		(env.ttf) ? TTF_Quit() : 0;
		SDL_Quit();
	}
	return (0);
}

int					sdl_init(t_sdlenv env)
{
	if (SDL_Init(SDL_INIT_FLAGS) != 0)
		return (error_manager(env, 0));
	if (env.img)
		if ((IMG_Init(IMG_INIT_FLAGS) & IMG_INIT_FLAGS)
			!= IMG_INIT_FLAGS)
			return (error_manager(env, 1));
	if (env.ttf)
		if (TTF_Init() == -1)
			return (error_manager(env, 2));
	if (env.mixer)
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024)
			== -1)
			return (error_manager(env, 3));
	return (1);
}
