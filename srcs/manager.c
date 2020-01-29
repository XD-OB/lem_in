/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 05:36:02 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 05:48:05 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			manage_ants_aao(t_lemin *lemin)
{
	int			nshots;
	int			i;

	i = 0;
	nshots = lemin->best_infos->n_shots;
	if (!(lemin->tab_ants =
		(t_stat_ants*)malloc(sizeof(t_stat_ants) * lemin->ants)))
		ft_error();
	init_tab_ants(lemin->tab_ants, lemin->ants);
	while (++i < nshots)
	{
		parallel_walk(lemin, lemin->best_infos, lemin->tab_ants);
		write(1, " ", 1);
	}
	parallel_walk(lemin, lemin->best_infos, lemin->tab_ants);
	write(1, "\n", 1);
}

void			manage_ants_pap(t_lemin *lemin)
{
	int			nshots;
	int			i;

	i = 0;
	nshots = lemin->best_infos->n_shots;
	if (!(lemin->tab_ants =
		(t_stat_ants*)malloc(sizeof(t_stat_ants) * lemin->ants)))
		ft_error();
	init_tab_ants(lemin->tab_ants, lemin->ants);
	while (i++ < nshots)
	{
		parallel_walk(lemin, lemin->best_infos, lemin->tab_ants);
		write(1, "\n", 1);
	}
}

void			manage_ants(t_lemin *lemin)
{
	t_room		room;

	room.id = lemin->end;
	if (bt_search_item(lemin->tab_bt[lemin->start], &room, &id_cmp))
		manage_ants_aao(lemin);
	else
		manage_ants_pap(lemin);
}
