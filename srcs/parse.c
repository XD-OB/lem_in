/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 04:04:35 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/31 06:14:20 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		is_coord(char **line, int i)
{
	if ((*line)[i] == '-' || (*line)[i] == '+')
		i++;
	if (!ft_isdigit((*line)[i++]))
		return (0);
	while (ft_isdigit((*line)[i]))
		i++;
	if ((*line)[i] != ' ')
		return (0);
	i++;
	if ((*line)[i] == '-' || (*line)[i] == '+')
		i++;
	if (!ft_isdigit((*line)[i++]))
		return (0);
	while (ft_isdigit((*line)[i]))
		i++;
	if ((*line)[i])
		return (0);
	return (1);
}

int				is_room(char **line)
{
	int			i;

	i = 0;
	if ((*line)[0] == 'L')
		return (0);
	while ((*line)[i] > 32 && (*line)[i] != ' ')
		i++;
	if ((*line)[i] != ' ')
		return (0);
	(*line)[i] = '\0';
	i++;
	return (is_coord(line, i));
}

int				is_link(char **line)
{
	int			eol;
	int			i;

	i = 0;
	if ((*line)[0] == 'L')
		return (0);
	while ((*line)[i] > 32 && (*line)[i] != '-')
		i++;
	if ((*line)[i] != '-')
		return (0);
	eol = i;
	(*line)[i] = '\0';
	i++;
	while (ft_isprint((*line)[i]))
		i++;
	if ((*line)[i])
		return (0);
	return (eol);
}

static void		parse_ants(t_lemin *lemin)
{
	char		*line;
	int			i;

	i = 0;
	if (!gnl_error(lemin, &line))
	{
		free(line);
		chr_free(&lemin->input);
		ft_error();
	}
	while (ft_isdigit(line[i]) && i < 7)
		i++;
	if (line[i])
	{
		free(line);
		chr_free(&lemin->input);
		ft_error();
	}
	lemin->ants = ft_atoi(line);
	free(line);
	if (lemin->ants <= 0)
	{
		chr_free(&lemin->input);
		ft_error();
	}
}

void			parse(t_lemin *lemin)
{
	t_chr		*list_tmp;
	char		*line;

	list_tmp = NULL;
	parse_ants(lemin);
	line = parse_rooms(lemin, &list_tmp);
	create_tabhash(lemin, list_tmp);
	chr_free(&list_tmp);
	if (lemin->start < 0 || lemin->end < 0)
		free_lemin(lemin, 1);
	parse_links(lemin, &line);
	chr_revprint(lemin->input);
	write(1, "\n", 1);
}
