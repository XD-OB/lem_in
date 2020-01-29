/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 04:13:15 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/30 04:13:32 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		exclus_path(t_lemin *lemin, t_icase *path)
{
	while (path)
	{
		lemin->exclus[path->n] = 1;
		path = path->next;
	}
	lemin->exclus[lemin->start] = 0;
	lemin->exclus[lemin->end] = 0;
}

void		ic_lstrevaddlast(t_list **head, t_icase *path, int *cap)
{
	t_list	*node;

	node = ic_revlstnew(path);
	ft_lstadd_last(head, node);
	(*cap)++;
}

int			qtic_deq(t_queue *queue)
{
	t_list	*tmp;
	t_icase	**curr;

	if (qt_isempty(*queue))
		return (1);
	tmp = queue->front;
	if (queue->front == queue->rear)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	else
		queue->front = queue->front->next;
	curr = tmp->content;
	ic_free(curr);
	free(tmp->content);
	free(tmp);
	return (0);
}

int			qtic_free(t_queue *queue)
{
	while (!qt_isempty(*queue))
		qtic_deq(queue);
	free(queue);
	queue = NULL;
	return (0);
}
