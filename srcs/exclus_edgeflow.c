/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclus_edgeflow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:41:19 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/29 04:31:58 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		edit_edgeflow(t_bt **tab_bt, int id1, int id2, t_room *room)
{
	t_room		*fnd_room;
	t_bt		*root;
	t_bt		*found;

	room->id = id2;
	root = tab_bt[id1];
	found = bt_search_item(root, room, &id_cmp);
	fnd_room = (t_room*)found->item;
	fnd_room->edge_flow = 0;
}

static void		limit_edgeflow(t_lemin *lemin, int id,
		t_room *room, int is_start)
{
	t_room		*fnd_room;
	t_bt		*found;
	t_bt		*root;

	root = (is_start) ? (lemin->tab_bt)[lemin->start] :
						(lemin->tab_bt)[lemin->end];
	if (bt_size_count(root) == 1)
		return ;
	room->id = id;
	found = bt_search_item(root, room, &id_cmp);
	fnd_room = (t_room*)found->item;
	fnd_room->edge_flow = 0;
}

static void		extrem_edgeflow(t_lemin *lemin, t_room *room)
{
	t_room		*fnd_room;
	t_bt		*found;
	t_bt		*root;

	root = (lemin->tab_bt)[lemin->start];
	room->id = lemin->end;
	found = bt_search_item(root, room, &id_cmp);
	fnd_room = (t_room*)found->item;
	fnd_room->edge_flow = 0;
}

void			update_edgeflow(t_lemin *lemin, t_icase *path)
{
	t_icase		*tmp;
	t_room		room;
	int			size;

	size = ic_size(path);
	if (size == 2)
		extrem_edgeflow(lemin, &room);
	if (size > 3)
	{
		tmp = path->next;
		if (tmp && tmp->next)
			tmp = tmp->next;
		edit_edgeflow(lemin->tab_bt, tmp->n, tmp->next->n, &room);
	}
	else
	{
		limit_edgeflow(lemin, path->next->n, &room, 1);
		limit_edgeflow(lemin, path->next->n, &room, 0);
	}
}

void			update_exclus(t_lemin *lemin, t_icase *path)
{
	t_icase		*tmp;

	tmp = (path) ? path->next : NULL;
	if (tmp && tmp->n == lemin->end)
		lemin->exclus[lemin->start] = 1;
	else
	{
		while (tmp && tmp->next)
		{
			lemin->exclus[tmp->n] = 1;
			tmp = tmp->next;
		}
	}
}
