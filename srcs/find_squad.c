/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_squad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 04:40:13 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/30 06:54:14 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		head_enq(t_lemin *lemin, t_bt *root, t_queue *q, t_icase *path)
{
	t_icase		*new;
	t_room		*room;

	if (root)
	{
		head_enq(lemin, root->right, q, path);
		room = (t_room*)root->item;
		if (!ic_find(path, room->id))
		{
			new = ic_copy(path);
			ic_pushnode(&new, room->id);
			qt_enqueue(q, &new, sizeof(t_icase**));
		}
		head_enq(lemin, root->left, q, path);
	}
}

/*
**  cap:	0:hold		1:switch algo
*/

int				find_heads(t_lemin *lemin)
{
	t_icase		*path;
	t_queue		*q;
	int			cap[2];

	cap[0] = 0;
	cap[1] = 0;
	path = NULL;
	q = qt_new_queue();
	ic_pushnode(&path, lemin->start);
	qt_enqueue(q, &path, sizeof(t_icase**));
	while (!qt_isempty(*q) && cap[0] < MAX_HEAD)
	{
		qt_front(*q, &path);
		if (path->n == lemin->end)
		{
			ic_lstrevaddlast(&lemin->head_grps, path, cap);
			qtic_deq(q);
			continue ;
		}
		head_enq(lemin, lemin->tab_bt[path->n], q, path);
		qtic_deq(q);
		if (++cap[1] == MAX_INF && cap[0] == 0)
			return (qtic_free(q));
	}
	return (qtic_free(q) + 1);
}

static void		second_enq(t_lemin *lemin, t_bt *root, t_queue *q,
							t_icase *path)
{
	t_icase		*new;
	t_room		*room;

	if (root)
	{
		second_enq(lemin, root->right, q, path);
		room = (t_room*)root->item;
		if (!lemin->exclus[room->id] && !ic_find(path, room->id))
		{
			new = ic_copy(path);
			ic_pushnode(&new, room->id);
			qt_enqueue(q, &new, sizeof(t_icase**));
		}
		second_enq(lemin, root->left, q, path);
	}
}

static void		reset_exclus_path(t_lemin *lemin, t_icase *head)
{
	tabint_reset(lemin->exclus, lemin->v, 0);
	exclus_path(lemin, head);
}

t_list			*find_vices(t_lemin *lemin, t_icase *head)
{
	t_list		*suggest;
	t_icase		*path;
	t_queue		*q;
	int			i;

	i = 0;
	suggest = NULL;
	path = ic_new(lemin->start);
	q = qt_new_queue();
	qt_enqueue(q, &path, sizeof(t_icase**));
	reset_exclus_path(lemin, head);
	while (!qt_isempty(*q) && i < MAX_VICE)
	{
		qt_front(*q, &path);
		if (path->n == lemin->end)
		{
			ic_lstrevaddlast(&suggest, path, &i);
			qtic_deq(q);
			continue ;
		}
		second_enq(lemin, lemin->tab_bt[path->n], q, path);
		qtic_deq(q);
	}
	qtic_free(q);
	return (suggest);
}
