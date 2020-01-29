/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_music.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:29:23 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/25 02:27:30 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsdl.h"

int		load_music(t_sdlenv *env, char *path_music)
{
	env->music = Mix_LoadMUS(path_music);
	if (!env->music)
	{
		ft_dprintf(2, "Error will Loading the Music: %s\n",
				Mix_GetError());
		return (0);
	}
	return (1);
}
