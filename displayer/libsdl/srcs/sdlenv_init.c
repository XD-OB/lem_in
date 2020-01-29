/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdlenv_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:59:04 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:59:17 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsdl.h"

void	sdlenv_init(t_sdlenv *env, int img, int ttf, int mixer)
{
	env->img = (img) ? 1 : 0;
	env->ttf = (ttf) ? 1 : 0;
	env->mixer = (mixer) ? 1 : 0;
	env->window = NULL;
	env->render = NULL;
	env->music = NULL;
}
