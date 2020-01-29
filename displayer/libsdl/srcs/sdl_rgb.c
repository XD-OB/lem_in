/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:33:39 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 20:54:51 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

SDL_Color		sdl_rgb(int r, int g, int b)
{
	SDL_Color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 1;
	return (color);
}
