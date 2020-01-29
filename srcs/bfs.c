/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:58:25 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 05:18:26 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		enq_infix(t_lemin *lemin, t_bt *root, t_queue *q, int u)
{
	t_room		*room;

	if (root)
	{
		room = (t_room*)root->item;
		enq_infix(lemin, root->right, q, u);
		if (!(lemin->visited)[room->id] && room->edge_flow)
		{
			qt_enqueue(q, &room->id, sizeof(int));
			(lemin->visited)[room->id] = 1;
			(lemin->parent)[room->id] = u;
		}
		enq_infix(lemin, root->left, q, u);
	}
}

static void		store_path(t_lemin *lemin)
{
	t_icase		*path;
	t_list		*node;
	int			u;

	u = lemin->end;
	path = NULL;
	while (u != lemin->start)
	{
		ic_pushnode(&path, u);
		u = lemin->parent[u];
	}
	ic_pushnode(&path, u);
	node = ic_lstnew_sm(path);
	ft_lstadd(&lemin->list_paths, node);
}

int				bfs(t_lemin *lemin)
{
	t_queue		*q;
	int			u;

	tabint_reset(lemin->visited, lemin->v, 0);
	q = qt_new_queue();
	u = lemin->start;
	qt_enqueue(q, &u, sizeof(int));
	(lemin->visited)[u] = 1;
	(lemin->parent)[u] = -1;
	while (!qt_isempty(*q))
	{
		qt_front(*q, &u);
		if (u == lemin->end)
		{
			store_path(lemin);
			qt_free(q);
			return (1);
		}
		qt_dequeue(q);
		if (!lemin->exclus[u])
			enq_infix(lemin, lemin->tab_bt[u], q, u);
	}
	qt_free(q);
	return (0);
}
