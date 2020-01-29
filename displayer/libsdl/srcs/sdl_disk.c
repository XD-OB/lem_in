/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_disk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 21:03:07 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 21:03:08 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

void	sdl_disk(t_sdlenv env, SDL_Color color, t_point c, int r)
{
	int	tmp_r;
	int	i;

	i = 0;
	tmp_r = r;
	while (tmp_r >= 0)
	{
		sdl_circle(env, color, c, tmp_r);
		i++;
		tmp_r--;
	}
}
