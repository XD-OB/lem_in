/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_places.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:04:50 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/25 10:05:51 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static int		alloc_tab_ants(t_infos *infos)
{
	int			nshots;
	int			ants;
	int			i;

	ants = infos->ants;
	nshots = infos->shots;
	if (!(infos->tab_ants = (t_ant_infos*)malloc(sizeof(t_ant_infos) * ants)))
		return (0);
	i = 0;
	while (i < ants)
	{
		if (!((infos->tab_ants)[i].tab_life =
					(int*)malloc(sizeof(int) * (nshots + 1))))
			return (0);
		tabint_reset(infos->tab_ants[i].tab_life, nshots + 1, -1);
		(infos->tab_ants)[i].color = L_BLACK;
		i++;
	}
	return (1);
}

int				alloc_places(t_infos *infos)
{
	int			v;
	int			i;
	int			j;

	v = infos->v;
	if (!(infos->rooms = (t_room*)malloc(sizeof(t_room) * v)))
		return (0);
	if (!(infos->links = (int**)malloc(sizeof(int*) * v)))
		return (0);
	i = -1;
	while (++i < v)
	{
		infos->rooms[i].color = L_WHITE;
		if (!(infos->links[i] = (int*)malloc(sizeof(int) * v)))
			return (0);
		j = -1;
		while (++j < v)
			infos->links[i][j] = 0;
	}
	alloc_tab_ants(infos);
	if (!(infos->start_end =
			(t_point*)malloc(sizeof(t_point) * (infos->shots + 1))))
		return (0);
	return (1);
}
