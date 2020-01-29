/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:55:36 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 06:44:29 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		parse_cmds(char *line, int *t, int *limit)
{
	if (!ft_strcmp(&line[2], "start"))
	{
		limit[0] = !limit[0] ? 1 : -1;
		*t = 1;
	}
	else if (!ft_strcmp(&line[2], "end"))
	{
		limit[1] = !limit[1] ? 1 : -1;
		*t = 2;
	}
}

static int		type_action(t_chr **list_tmp, char **line, int *limit, int *t)
{
	if ((*line)[0] == '#')
	{
		if (*t)
			return (-1);
		parse_cmds(*line, t, limit);
		return (2);
	}
	if (is_room(line))
	{
		chr_pushfront(list_tmp, *line, *t);
		*t = 0;
		return (2);
	}
	if (is_link(line))
	{
		if (limit[0] == 1 && limit[1] == 1)
			return (0);
	}
	return (1);
}

char			*parse_rooms(t_lemin *lemin, t_chr **list_tmp)
{
	char		*line;
	int			limit[2];
	int			ret;
	int			t;

	t = 0;
	limit[0] = 0;
	limit[1] = 0;
	while (gnl_error(lemin, &line))
	{
		ret = type_action(list_tmp, &line, limit, &t);
		if (ret == 0)
			return (line);
		if (ret == 1)
			break ;
		free(line);
		line = NULL;
		if (ret == -1)
			free_lemin(lemin, 1);
	}
	(line) ? free(line) : 0;
	(*list_tmp) ? chr_free(list_tmp) : 0;
	free_lemin(lemin, 1);
	return (NULL);
}

static int		add_links(t_lemin *lemin, int n_vertex, char **link, int eol)
{
	t_room		*room_a;
	t_room		*room_b;
	int			a;
	int			b;

	a = hash_findid(lemin->tab_hash, n_vertex, *link);
	b = hash_findid(lemin->tab_hash, n_vertex, &(*link)[eol]);
	free(*link);
	if (a == -1 || b == -1)
		return (0);
	room_a = create_room(a);
	room_b = create_room(b);
	if (!bt_search_item(lemin->tab_bt[a], room_b, &id_cmp) &&
		!bt_search_item(lemin->tab_bt[b], room_a, &id_cmp))
	{
		bt_insert_item(&(lemin->tab_bt)[a], room_b, &id_cmp);
		bt_insert_item(&(lemin->tab_bt)[b], room_a, &id_cmp);
	}
	else
	{
		free(room_a);
		free(room_b);
		return (0);
	}
	return (1);
}

void			parse_links(t_lemin *lemin, char **bk_line)
{
	char		*line;
	int			eol;
	int			v;
	int			i;

	v = lemin->v;
	if (!(lemin->tab_bt = (t_bt**)malloc(sizeof(t_bt*) * (v + 1))))
		ft_error();
	i = 0;
	while (i <= v)
		(lemin->tab_bt)[i++] = NULL;
	eol = ft_strlen(*bk_line);
	add_links(lemin, lemin->v, bk_line, eol + 1);
	while (gnl_error(lemin, &line))
	{
		if (!(eol = is_link(&line)))
		{
			free(line);
			free_lemin(lemin, 1);
		}
		if (!add_links(lemin, lemin->v, &line, eol + 1))
			free_lemin(lemin, 1);
	}
	free(line);
}
