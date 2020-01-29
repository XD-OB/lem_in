/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:44:21 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 19:44:23 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsdl.h"

void		sdl_close(t_sdlenv *env)
{
	if (env->music)
		Mix_FreeMusic(env->music);
	if (env->mixer)
		Mix_CloseAudio();
	if (env->ttf)
		TTF_Quit();
	if (env->img)
		IMG_Quit();
	SDL_DestroyRenderer(env->render);
	SDL_DestroyWindow(env->window);
	SDL_Quit();
}
