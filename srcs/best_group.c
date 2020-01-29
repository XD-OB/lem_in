/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 05:57:58 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/29 03:35:38 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		find_min_shots(t_infos *infos, int size)
{
	int		index_min;
	int		i;

	i = 0;
	index_min = 0;
	while (i < size)
	{
		if (infos[index_min].n_shots > infos[i].n_shots)
			index_min = i;
		i++;
	}
	return (index_min);
}

static void		best_choice(t_lemin *lemin)
{
	t_infos	*infos;
	t_list	*grps;
	int		index_min;
	int		i;

	infos = lemin->grp_infos;
	grps = lemin->list_grp;
	index_min = find_min_shots(infos, lemin->ngrp);
	i = 0;
	while (i++ < index_min)
		grps = grps->next;
	lemin->best_grp = (t_list*)(grps->content);
	lemin->best_infos = &(infos[index_min]);
}

void			find_best_grp(t_lemin *lemin)
{
	t_list		*grp;
	int			ngrp;
	int			i;

	ngrp = lemin->ngrp;
	if (!(lemin->grp_infos =
		(t_infos*)malloc(sizeof(t_infos) * (ngrp))))
		ft_error();
	i = 0;
	grp = lemin->list_grp;
	while (i < ngrp)
	{
		fill_grp_infos(lemin, grp->content, &(lemin->grp_infos[i]));
		grp = grp->next;
		i++;
	}
	best_choice(lemin);
}
