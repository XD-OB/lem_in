/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 05:43:23 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 05:44:24 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_icase			*after_start_path(t_list *best, int index)
{
	int			i;

	i = 0;
	while (i++ < index)
		best = best->next;
	return (((t_icase*)(best->content))->next);
}

static void		print_l(char **tab_hash, int a, int b, int *flag)
{
	if (*flag)
		ft_putchar(' ');
	if (!*flag)
		*flag = 1;
	ft_putchar('L');
	ft_putnbr(a);
	ft_putchar('-');
	ft_putstr(tab_hash[b]);
}

static int		move_ant(t_lemin *lemin, int i, int j, int *flag)
{
	t_stat_ants	*tab_ants;
	t_infos		*infos;

	infos = lemin->best_infos;
	tab_ants = lemin->tab_ants;
	if (!tab_ants[j].pos)
	{
		if (infos->paths[i].ants > 0)
		{
			tab_ants[j].pos = after_start_path(lemin->best_grp, i);
			tab_ants[j].id_path = i;
			print_l(lemin->tab_hash, j + 1, tab_ants[j].pos->n, flag);
			infos->paths[i].ants--;
		}
		return (0);
	}
	else
	{
		tab_ants[j].pos = tab_ants[j].pos->next;
		if (tab_ants[j].pos)
			print_l(lemin->tab_hash, j + 1, tab_ants[j].pos->n, flag);
		else
			tab_ants[j].finish = 1;
	}
	return (1);
}

void			parallel_walk(t_lemin *lemin, t_infos *infos,
								t_stat_ants *tab_ants)
{
	int			npaths;
	int			nsubs;
	int			flag;
	int			i;
	int			j;

	flag = 0;
	nsubs = infos->n_subs;
	npaths = infos->n_paths;
	i = npaths;
	while (--i >= 0 && nsubs-- > 0)
	{
		j = -1;
		while (++j < lemin->ants)
		{
			if (!tab_ants[j].finish &&
					(tab_ants[j].id_path == -1 || tab_ants[j].id_path == i))
				if (!move_ant(lemin, i, j, &flag))
					break ;
		}
	}
}
