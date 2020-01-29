/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 05:17:29 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 06:40:56 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

int		is_ignored(char *str)
{
	if (str[0] == '#' && str[1] != '#')
		return (1);
	return (0);
}

int		gnl_error(t_lemin *lemin, char **line)
{
	int		ret;

	ret = get_next_line(0, line);
	if (ret < 0)
		ft_error();
	chr_pushfront(&lemin->input, *line, 0);
	while (is_ignored(*line))
	{
		free(*line);
		ret = get_next_line(0, line);
		if (ret < 0)
			ft_error();
		chr_pushfront(&lemin->input, *line, 0);
	}
	return (ret);
}

int		id_cmp(void *item1, void *item2)
{
	t_room	*room1;
	t_room	*room2;

	room1 = (t_room*)item1;
	room2 = (t_room*)item2;
	if (room1->id == room2->id)
		return (0);
	if (room1->id > room2->id)
		return (-1);
	return (1);
}
