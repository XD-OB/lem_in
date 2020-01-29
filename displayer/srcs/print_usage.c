/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 02:54:22 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/26 03:04:01 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void			print_usage(void)
{
	ft_printf("%{blue}=====================|%{BLUE} USAGE %{blue}|");
	ft_printf("==================%{eoc}\n");
	ft_printf("        %{GREEN}* Displayer commands:%{eoc}\n");
	ft_printf("   Exit        :  %{CYAN}ESCAPE%{eoc}\n");
	ft_printf("   Move        :  %{CYAN}ARROWS%{eoc}\n");
	ft_printf("   Pause       :  %{CYAN}SPACE%{eoc}\n");
	ft_printf("   Reset       :  %{CYAN}R%{eoc}\n");
	ft_printf("   Zoom In     :  %{CYAN}+%{eoc}\n");
	ft_printf("   Zoom Out    :  %{CYAN}-%{eoc}\n");
	ft_printf("   Next Shot   :  %{CYAN}F%{eoc}\n");
	ft_printf("   Prev Shot   :  %{CYAN}B%{eoc}\n");
	ft_printf("   Speed Up    :  %{CYAN}2%{eoc}\n");
	ft_printf("   Speed Down  :  %{CYAN}1%{eoc}\n");
	ft_printf("   Trace On/Off:  %{CYAN}T%{eoc}\n");
	ft_printf("   Music On/Off:  %{CYAN}M%{eoc}\n");
	ft_printf("\n        %{GREEN}* Map commands:%{eoc}\n");
	ft_printf("  %{cyan}##color room %{eoc}room_name%{cyan}-%{eoc}color\n");
	ft_printf("  %{cyan}##color ant %{eoc}ant_num%{cyan}-%{eoc}color\n");
	ft_printf("\n        %{GREEN}* Colors:%{eoc}\n");
	ft_printf(" %{RED}RED %{BLUE}BLUE %{GREEN}GREEN %{YELLOW}YELLOW");
	ft_printf(" %{CYAN}CYAN %{eoc}ORANGE %{PURPLE}PURPLE\n");
	ft_printf("%{blue}========================");
	ft_printf("=========================%{eoc}\n");
}
