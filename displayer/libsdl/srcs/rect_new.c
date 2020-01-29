/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:42:04 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 19:42:05 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libsdl.h"

SDL_Rect			rect_new(int height, int width, int y, int x)
{
	SDL_Rect		rect;

	rect.h = height;
	rect.w = width;
	rect.y = y;
	rect.x = x;
	return (rect);
}
