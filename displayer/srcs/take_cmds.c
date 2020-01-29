/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 06:42:50 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/25 10:45:46 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static int		good_ant_syntax(char **s)
{
	char		*str;
	int			eol;
	int			i;

	i = 0;
	str = *s;
	while (str[i] && str[i] != '-')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	eol = i;
	while (str[++i])
		if (str[i] < 65 && str[i] > 90)
			return (0);
	(*s)[eol] = '\0';
	return (eol);
}

static void		set_ant_color(t_infos *infos, char *str)
{
	int			eol;
	int			n;

	eol = good_ant_syntax(&str);
	if (eol > 0)
	{
		n = ft_atoi(str);
		if (n > 0 && n - 1 < infos->ants)
			infos->tab_ants[n - 1].color = the_color(&str[eol + 1], L_BLACK);
		else
			ft_dprintf(2, "The number of ant to colorize is incorrect!\n");
	}
}

static int		good_room_syntax(char **s)
{
	char		*str;
	int			eol;
	int			i;

	i = 0;
	str = *s;
	while (str[i] && str[i] != '-')
	{
		if (str[i] < 32 && str[i] > 126)
			return (0);
		i++;
	}
	eol = i;
	while (str[++i])
		if (str[i] < 65 && str[i] > 90)
			return (0);
	(*s)[eol] = '\0';
	return (eol);
}

static void		set_room_color(t_infos *infos, char *str)
{
	int			eol;
	int			n;

	eol = good_room_syntax(&str);
	if (eol > 0)
	{
		n = hash_findid(infos->tab_hash, infos->v, str);
		if (n != -1)
			infos->rooms[n].color = the_color(&str[eol + 1], L_WHITE);
		else
			ft_dprintf(2, "The name of rooom to colorize is incorrect!\n");
	}
}

void			take_cmds(t_infos *infos, char *str)
{
	if (!ft_strncmp(str, "##color branch ", 15))
		infos->color_paths = the_color(&str[15], L_WHITE);
	else if (!ft_strncmp(str, "##color ant ", 12))
		set_ant_color(infos, &str[12]);
	else if (!ft_strncmp(str, "##color room ", 13))
		set_room_color(infos, &str[13]);
}
