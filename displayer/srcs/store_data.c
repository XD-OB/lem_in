/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:28:54 by ishaimou          #+#    #+#             */
/*   Updated: 2019/07/29 05:22:43 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void			fill_trace(t_infos *infos)
{
	int			*life;
	int			i;
	int			j;

	i = 0;
	while (i < infos->ants)
	{
		j = 0;
		while (j < infos->shots)
		{
			life = infos->tab_ants[i].tab_life;
			if (life[j] != -1 && life[j + 1] != -1 &&
					life[j] != life[j + 1])
			{
				if (infos->links[life[j]][life[j + 1]] == 2)
					break ;
				infos->links[life[j]][life[j + 1]] = 2;
				infos->links[life[j + 1]][life[j]] = 2;
			}
			j++;
		}
		i++;
	}
}

void			take_options(int ac, char **av, t_infos *infos)
{
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "-d"))
			infos->debug = 1;
		else
		{
			free_infos(infos);
			ft_dprintf(2, "Usage: ./test [-d]\n");
			ft_dprintf(2, "  -d : enable debug mode\n");
			exit(EXIT_FAILURE);
		}
	}
}

static void		find_start_end(t_chr *curr, char *str)
{
	if (!ft_strcmp(str, "start"))
		curr->next->len = INT_MAX;
	else if (!ft_strcmp(str, "end"))
		curr->next->len = UINT_MAX;
}

void			fill_basic_infos(t_infos *infos)
{
	t_chr		*curr;
	char		*str;

	curr = infos->input;
	if (!ft_strncmp(curr->str, "ERROR", 5))
		free_error(infos);
	while (curr)
	{
		str = curr->str;
		if (str[0] == '#')
		{
			if (str[1] != '#')
				ft_putendl(&str[1]);
			else
				find_start_end(curr, &str[2]);
		}
		else if (is_strnbr(str))
			infos->ants = ft_atoi(str);
		else if (is_room(str))
			infos->v++;
		else if (str[0] == 'L')
			infos->shots++;
		curr = curr->next;
	}
}

int				store_data(int ac, char **av, t_infos *infos)
{
	init_infos(infos);
	take_options(ac, av, infos);
	if (!(infos->input = gnl_save_chr(0)))
		return (0);
	chr_print(infos->input);
	ft_putstr("\n\n");
	fill_basic_infos(infos);
	if (!alloc_places(infos))
	{
		free_infos(infos);
		exit(0);
	}
	create_tabhash_2(infos, infos->input);
	fill_adv_infos(infos);
	fill_start_end(infos);
	fill_trace(infos);
	if (infos->debug)
		print_debug(infos);
	return (1);
}
