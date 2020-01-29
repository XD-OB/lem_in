/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ishobe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:30:23 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/30 10:33:44 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		classic_grpmaker(t_lemin *lemin)
{
	t_icase		*path;

	tabint_reset(lemin->exclus, lemin->v, 0);
	if (bfs(lemin))
	{
		path = (t_icase*)(lemin->list_paths->content);
		update_edgeflow(lemin, path);
		update_exclus(lemin, path);
	}
	else
		return (0);
	while (bfs(lemin))
	{
		path = (t_icase*)(lemin->list_paths->content);
		update_exclus(lemin, path);
	}
	if (!(lemin->list_paths))
		return (0);
	return (1);
}

static void		classic_ishobe(t_lemin *lemin)
{
	t_list		*node;
	t_list		*tmp;

	while (classic_grpmaker(lemin))
	{
		node = ft_lstnew_sm(lemin->list_paths, sizeof(t_list*));
		ft_lstadd(&lemin->list_grp, node);
		(lemin->ngrp)++;
		while (lemin->list_paths)
		{
			tmp = lemin->list_paths;
			lemin->list_paths = lemin->list_paths->next;
			tmp = NULL;
		}
	}
	if (!(lemin->list_grp))
		free_lemin(lemin, 1);
}

void			algo_ishobe(t_lemin *lemin)
{
	if (!find_heads(lemin))
		classic_ishobe(lemin);
	else
		ultimate_ishobe(lemin);
}
