/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdlenv_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:46:11 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:58:58 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsdl.h"

static int	error_sdlenv(t_sdlenv *env, int type)
{
	if (type == 0)
		ft_dprintf(2, "%{RED}Error will creating the Window: %{eoc}%s\n",
				SDL_GetError());
	else
	{
		ft_dprintf(2, "%{RED}Error will creating the Renderer: %{eoc}%s\n",
				SDL_GetError());
		SDL_DestroyWindow(env->window);
	}
	if (env->img)
		IMG_Quit();
	if (env->ttf)
		TTF_Quit();
	if (env->mixer)
		Mix_Quit();
	SDL_Quit();
	return (0);
}

int			sdlenv_fill(t_sdlenv *env, char *title, int height, int width)
{
	env->window = SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width, height, 0);
	if (!env->window)
		return (error_sdlenv(env, 0));
	env->render = SDL_CreateRenderer(
			env->window, -1,
			SDL_RENDERER_ACCELERATED);
	if (!env->render)
		return (error_sdlenv(env, 1));
	return (1);
}
