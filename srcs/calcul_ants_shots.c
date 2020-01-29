/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_ants_shots.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 03:35:58 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/29 03:40:48 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	calc_max_shots(t_paths *paths, int n_paths)
{
	int		max_shots;
	int		i;

	i = 0;
	max_shots = 0;
	while (i < n_paths)
	{
		if (paths[i].ants > 0)
			if (max_shots < paths[i].len + paths[i].ants)
				max_shots = paths[i].len + paths[i].ants;
		i++;
	}
	return (max_shots);
}

static int	sum_subpathslen(t_paths *paths, int n_paths, int n_subs)
{
	int		sum;
	int		i;

	sum = 0;
	i = n_paths;
	while (--i >= 0 && n_subs-- > 0)
		sum += paths[i].len;
	return (sum);
}

void		fill_path_ant(t_paths *path, int *ants, int avg)
{
	int		phi;

	phi = ft_max(avg - path->len, 0);
	path->ants = (*ants > phi) ? phi : *ants;
	*ants -= path->ants;
}

int			calcul_ants_shots(int ants, t_infos *infos, int n_subs)
{
	t_paths	*paths;
	int		n_paths;
	int		nsubs;
	int		avg;
	int		i;

	n_paths = infos->n_paths;
	paths = infos->paths;
	avg = (ants + sum_subpathslen(paths, n_paths, n_subs)) / n_subs;
	i = n_paths;
	nsubs = n_subs;
	while (--i >= 0 && nsubs-- > 0 && ants > 0)
		fill_path_ant(&paths[i], &ants, avg);
	while (ants > 0)
	{
		i = n_paths;
		nsubs = n_subs;
		while (--i >= 0 && nsubs-- > 0 && ants > 0)
		{
			paths[i].ants++;
			ants--;
		}
	}
	return (calc_max_shots(paths, n_paths));
}
