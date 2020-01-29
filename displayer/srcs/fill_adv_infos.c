/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_adv_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:24:49 by ishaimou          #+#    #+#             */
/*   Updated: 2019/07/31 07:22:25 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static void		begin_state(t_infos *infos, t_chr *curr)
{
	int			time;
	int			i;
	int			j;

	time = 1;
	while (curr)
	{
		fill_tab_ants(infos, infos->tab_ants, curr->str, time);
		curr = curr->next;
		time++;
	}
	i = 0;
	while (i < infos->ants)
	{
		j = 0;
		while (j <= infos->shots)
		{
			if (infos->tab_ants[i].tab_life[j] != -1)
				break ;
			infos->tab_ants[i].tab_life[j] = infos->start;
			j++;
		}
		i++;
	}
}

void			fill_room(t_infos *infos, char *str)
{
	char		**tab;
	int			ind;

	tab = ft_strsplit(str, ' ');
	ind = hash_findid(infos->tab_hash, infos->v, tab[0]);
	infos->rooms[ind].id = ind;
	infos->rooms[ind].coord.x = ft_atoi(tab[1]);
	infos->rooms[ind].coord.y = ft_atoi(tab[2]);
	free_tabstr(&tab);
}

void			add_link(char **tab_hash, int v, int **matrix, char *str)
{
	char		**tab;
	int			a;
	int			b;

	tab = ft_strsplit(str, '-');
	a = hash_findid(tab_hash, v, tab[0]);
	b = hash_findid(tab_hash, v, tab[1]);
	matrix[a][b] = 1;
	matrix[b][a] = 1;
}

void			fill_adv_infos(t_infos *infos)
{
	t_chr		*curr;

	curr = infos->input;
	while (curr)
	{
		if (curr->str[0] != '#')
		{
			if (is_room(curr->str))
				fill_room(infos, curr->str);
			else if (is_link(curr->str))
				add_link(infos->tab_hash, infos->v, infos->links, curr->str);
			else if (curr->str[0] == 'L')
				break ;
		}
		else if (curr->str[1] == '#')
			take_cmds(infos, curr->str);
		curr = curr->next;
	}
	begin_state(infos, curr);
}
