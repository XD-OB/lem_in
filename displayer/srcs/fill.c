/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:51:48 by ishaimou          #+#    #+#             */
/*   Updated: 2019/07/26 00:55:14 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static int		modify_l(char **str)
{
	char		*s;
	int			i;

	i = 1;
	s = *str;
	while (s[i] && s[i] != '-')
		i++;
	(*str)[i] = '\0';
	return (i);
}

void			fill_tab_ants(t_infos *infos, t_ant_infos *tab_ants,
		char *str, int time)
{
	char		**tab_cmds;
	int			num_ant;
	int			id_room;
	int			eol;
	int			i;

	i = 0;
	tab_cmds = ft_strsplit(str, ' ');
	while (tab_cmds[i])
	{
		eol = modify_l(&tab_cmds[i]);
		num_ant = ft_atoi(&(tab_cmds[i][1]));
		id_room = hash_findid(infos->tab_hash, infos->v, &tab_cmds[i][eol + 1]);
		tab_ants[num_ant - 1].tab_life[time] = id_room;
		i++;
	}
	free_tabstr(&tab_cmds);
}

static int		in_start(t_infos *infos, int x)
{
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (i < infos->ants)
	{
		if (infos->tab_ants[i].tab_life[x] != -1 &&
			infos->tab_ants[i].tab_life[x] != infos->start &&
			infos->tab_ants[i].tab_life[x - 1] == infos->start)
			count++;
		i++;
	}
	return (count);
}

static int		in_end(t_infos *infos, int x)
{
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (i < infos->ants)
	{
		if (infos->tab_ants[i].tab_life[x] == infos->end)
			count++;
		i++;
	}
	return (count);
}

void			fill_start_end(t_infos *infos)
{
	int			start;
	int			end;
	int			i;

	i = 0;
	end = 0;
	start = infos->ants;
	while (i <= infos->shots)
	{
		end += in_end(infos, i);
		start -= in_start(infos, i);
		infos->start_end[i].y = end;
		infos->start_end[i].x = start;
		i++;
	}
}
