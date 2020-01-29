/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 04:33:17 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/30 10:32:19 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			hash_strtoind_e(char **tab_hash, int size, char *str)
{
	int		ind;
	int		i;

	ind = hash_str(str) % size;
	if (!tab_hash[ind])
		return (ind);
	if (hash_findid(tab_hash, size, str) == -1)
	{
		i = ind + 1;
		while (i < size)
		{
			if (!tab_hash[i])
				return (i);
			i++;
		}
		i = 0;
		while (i < ind)
		{
			if (!tab_hash[i])
				return (i);
			i++;
		}
	}
	return (-1);
}

void		create_tabhash(t_lemin *lemin, t_chr *list_tmp)
{
	int		ind;
	int		v;
	int		i;

	v = chr_len(list_tmp);
	if (!v)
		ft_error();
	lemin->v = v;
	if (!(lemin->tab_hash = (char**)malloc(sizeof(char*) * v)))
		ft_error();
	i = 0;
	while (i < v)
		(lemin->tab_hash)[i++] = NULL;
	while (list_tmp)
	{
		ind = hash_strtoind_e(lemin->tab_hash, v, list_tmp->str);
		if (ind == -1)
			free_lemin(lemin, 1);
		hash_putintab(lemin->tab_hash, v, list_tmp->str, &ind);
		if (list_tmp->len == 1)
			lemin->start = ind;
		if (list_tmp->len == 2)
			lemin->end = ind;
		list_tmp = list_tmp->next;
	}
}

t_room		*create_room(int room_id)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		ft_error();
	room->id = room_id;
	room->ext_edge_flow = 1;
	room->edge_flow = 1;
	room->forwd = 0;
	room->backwd = 0;
	return (room);
}
