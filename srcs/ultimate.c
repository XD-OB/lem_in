/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 05:24:21 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 05:57:50 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		create_grp(t_lemin *lemin, t_icase *head,
							t_icase *second)
{
	t_list		*scd;
	t_icase		*path;

	scd = ic_lstnew_sm(second);
	lemin->list_paths = ic_lstnew(head);
	ft_lstadd(&lemin->list_paths, scd);
	tabint_reset(lemin->exclus, lemin->v, 0);
	exclus_path(lemin, head);
	exclus_path(lemin, second);
	while (bfs(lemin))
	{
		path = (t_icase*)(lemin->list_paths->content);
		update_exclus(lemin, path);
	}
	if (!(lemin->list_paths))
		return (0);
	return (1);
}

static int		create_simple_grp(t_lemin *lemin, t_icase *head)
{
	t_icase		*path;

	lemin->list_paths = ic_lstnew(head);
	tabint_reset(lemin->exclus, lemin->v, 0);
	exclus_path(lemin, head);
	while (bfs(lemin))
	{
		path = (t_icase*)(lemin->list_paths->content);
		update_exclus(lemin, path);
	}
	if (!(lemin->list_paths))
		return (0);
	return (1);
}

static void		ultimate_grpmaker(t_lemin *lemin, t_list *second, t_list *head)
{
	t_list		*curr;
	t_list		*node;
	t_list		*tmp;

	curr = second;
	while (curr)
	{
		create_grp(lemin, head->content, curr->content);
		node = ft_lstnew_sm(lemin->list_paths, sizeof(t_list*));
		ft_lstadd(&lemin->list_grp, node);
		(lemin->ngrp)++;
		tmp = lemin->list_paths;
		lemin->list_paths = lemin->list_paths->next;
		tmp = NULL;
		curr = curr->next;
	}
}

static void		simple_grpmaker(t_lemin *lemin, t_list *head)
{
	t_list		*node;
	t_list		*tmp;

	create_simple_grp(lemin, head->content);
	node = ft_lstnew_sm(lemin->list_paths, sizeof(t_list*));
	ft_lstadd(&lemin->list_grp, node);
	(lemin->ngrp)++;
	tmp = lemin->list_paths;
	lemin->list_paths = lemin->list_paths->next;
	tmp = NULL;
}

void			ultimate_ishobe(t_lemin *lemin)
{
	t_list		*curr;
	t_list		*second;

	curr = lemin->head_grps;
	while (curr)
	{
		second = find_vices(lemin, curr->content);
		if (second)
		{
			ultimate_grpmaker(lemin, second, curr);
			ft_lstextfree(&second);
		}
		else
			simple_grpmaker(lemin, curr);
		curr = curr->next;
	}
	if (!(lemin->list_grp))
		free_lemin(lemin, 1);
}
