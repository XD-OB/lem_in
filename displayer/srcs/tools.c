/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 01:58:50 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/30 04:07:55 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

int			the_color(char *str, int def)
{
	if (!ft_strcmp(str, "RED"))
		return (L_RED);
	if (!ft_strcmp(str, "BLUE"))
		return (L_BLUE);
	if (!ft_strcmp(str, "YELLOW"))
		return (L_YELLOW);
	if (!ft_strcmp(str, "GREEN"))
		return (L_GREEN);
	if (!ft_strcmp(str, "CYAN"))
		return (L_CYAN);
	if (!ft_strcmp(str, "ORANGE"))
		return (L_ORANGE);
	if (!ft_strcmp(str, "PURPLE"))
		return (L_PURPLE);
	return (def);
}

int			is_link(char *str)
{
	int		i;

	i = 0;
	if (str[0] == 'L' || str[0] == '#')
		return (0);
	while (str[i] > 32 && str[i] != '-')
		i++;
	if (str[i++] != '-')
		return (0);
	while (str[i] > 32 && str[i] < 127)
		i++;
	if (str[i])
		return (0);
	return (1);
}

int			is_room(char *str)
{
	int		i;

	i = -1;
	if (str[0] == 'L' || str[0] == '#')
		return (0);
	while (str[++i] && str[i] != ' ')
		if (!ft_isprint(str[i]))
			return (0);
	if (str[i] != ' ')
		return (0);
	while (str[++i] && str[i] != ' ')
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
	if (str[i] != ' ')
		return (0);
	while (str[++i])
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
	return ((str[i]) ? 0 : 1);
}

int			is_strnbr(char *str)
{
	int		i;

	i = -1;
	if (str[0] == '\0')
		return (0);
	while (str[++i])
		if (str[i] < 48 || str[i] > 57)
			return (0);
	return (1);
}

int			get_teta(t_infos infos, int a, int b)
{
	t_point	p[2];
	float	teta;

	if (b == -1 || a == infos.end)
		return (0);
	p[0] = infos.rooms[a].coord;
	p[1] = infos.rooms[b].coord;
	teta = pt_diffteta(p[0], p[1]);
	if (p[0].x < p[1].x || p[0].y < p[1].y)
		teta += 180;
	return (teta);
}
