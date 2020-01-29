/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grp_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:45:18 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/29 03:46:06 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		init_paths_ants(t_paths *paths, int n_paths)
{
	int			i;

	i = 0;
	while (i < n_paths)
	{
		paths[i].ants = 0;
		i++;
	}
}

static void		calcul_obeish(int ants, t_infos *infos)
{
	t_paths		*paths;
	int			n_paths;
	int			n_shots;
	int			n_subs;

	n_paths = infos->n_paths;
	paths = infos->paths;
	infos->n_shots = INT_MAX;
	n_subs = 1;
	infos->n_subs = 1;
	while (n_subs <= n_paths)
	{
		init_paths_ants(paths, n_paths);
		n_shots = calcul_ants_shots(ants, infos, n_subs);
		if (n_shots <= infos->n_shots)
		{
			infos->n_shots = n_shots;
			infos->n_subs = n_subs;
		}
		else
			break ;
		n_subs++;
	}
	init_paths_ants(paths, n_paths);
	calcul_ants_shots(ants, infos, infos->n_subs);
}

void			fill_grp_infos(t_lemin *lemin, t_list *grp, t_infos *infos)
{
	t_paths		*infos_paths;
	int			i;

	i = 0;
	infos->n_paths = ft_list_size(grp);
	infos->paths = (t_paths*)malloc(sizeof(t_paths) * infos->n_paths);
	infos_paths = infos->paths;
	while (grp)
	{
		infos_paths[i].len = ic_size((t_icase*)(grp->content)) - 2;
		grp = grp->next;
		i++;
	}
	calcul_obeish(lemin->ants, infos);
}
