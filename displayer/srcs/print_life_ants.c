/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_life_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:29:03 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/25 10:45:11 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static void		ant_life_color(char *str, int macros)
{
	if (macros == L_YELLOW)
		ft_printf(" %{yellow}%s%{eoc} |", str);
	else if (macros == L_GREEN)
		ft_printf(" %{green}%s%{eoc} |", str);
	else if (macros == L_RED)
		ft_printf(" %{red}%s%{eoc} |", str);
	else if (macros == L_BLUE)
		ft_printf(" %{blue}%s%{eoc} |", str);
	else if (macros == L_CYAN)
		ft_printf(" %{cyan}%s%{eoc} |", str);
	else if (macros == L_PURPLE)
		ft_printf(" %{purple}%s%{eoc} |", str);
	else
		ft_printf(" %s |", str);
}

static int		color_room(t_infos *infos, int id)
{
	int			i;

	i = 0;
	while (i < infos->v)
	{
		if (infos->rooms[i].id == id)
			return (infos->rooms[i].color);
		i++;
	}
	return (L_WHITE);
}

static void		print_instance_life(t_infos *infos, int i, int j)
{
	int			a;

	a = infos->tab_ants[i].tab_life[j];
	if (a != -1)
	{
		if (a == infos->start)
			ft_printf(" %{blue}%s%{eoc} |", infos->tab_hash[a]);
		else if (a == infos->end)
			ft_printf(" %{green}%s%{eoc} |", infos->tab_hash[a]);
		else
			ant_life_color(infos->tab_hash[a], color_room(infos, a));
	}
	else
		ft_printf(" %{green}%s%{eoc} |", infos->tab_hash[infos->end]);
}

void			print_life_ants(t_infos *infos)
{
	int			i;
	int			j;

	i = 0;
	ft_printf(" %{CYAN}Ants course:%{eoc}\n\n");
	while (i < infos->ants)
	{
		ft_printf("%{yellow}........%{eoc} ant %d ", i + 1);
		ft_printf("%{yellow}........%{eoc}\n\n");
		name_color(infos->tab_ants[i].color);
		ft_printf("   course:\n");
		j = -1;
		while (++j <= infos->shots)
			print_instance_life(infos, i, j);
		ft_printf("\n\n");
		i++;
	}
	ft_printf("\n");
}
