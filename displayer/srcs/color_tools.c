/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:12:06 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/25 10:18:33 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

SDL_Color	color_macros(int macros)
{
	if (macros == L_YELLOW)
		return (sdl_rgb(255, 255, 0));
	if (macros == L_WHITE)
		return (sdl_rgb(255, 255, 255));
	if (macros == L_BLACK)
		return (sdl_rgb(0, 0, 0));
	if (macros == L_GREEN)
		return (sdl_rgb(0, 255, 0));
	if (macros == L_RED)
		return (sdl_rgb(255, 0, 0));
	if (macros == L_BLUE)
		return (sdl_rgb(0, 0, 255));
	if (macros == L_ORANGE)
		return (sdl_rgb(255, 70, 0));
	if (macros == L_CYAN)
		return (sdl_rgb(0, 255, 255));
	if (macros == L_PURPLE)
		return (sdl_rgb(186, 85, 211));
	return (sdl_rgb(0, 0, 0));
}

void		name_color(int macros)
{
	if (macros == L_YELLOW)
		ft_printf("   color: %{yellow}Yellow%{eoc}\n");
	else if (macros == L_WHITE)
		ft_printf("   color: White\n");
	else if (macros == L_BLACK)
		ft_printf("   color: Black\n");
	else if (macros == L_GREEN)
		ft_printf("   color: %{green}Green%{eoc}\n");
	else if (macros == L_RED)
		ft_printf("   color: %{red}Red%{eoc}\n");
	else if (macros == L_BLUE)
		ft_printf("   color: %{blue}Blue%{eoc}\n");
	else if (macros == L_ORANGE)
		ft_printf("   color: Orange\n");
	else if (macros == L_CYAN)
		ft_printf("   color: %{cyan}Cyan%{eoc}\n");
	else if (macros == L_PURPLE)
		ft_printf("   color: %{purple}Purple%{eoc}\n");
	else
		ft_printf("   color: White\n");
}
