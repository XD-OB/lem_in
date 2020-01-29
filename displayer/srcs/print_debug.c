/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:41:24 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/29 05:23:43 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

static void		print_infos_rooms(char **tab_hash, t_room *rooms, int size)
{
	int			i;

	i = 0;
	ft_printf("\n %{CYAN}Rooms Informations:%{eoc}\n");
	while (i < size)
	{
		ft_printf("%{yellow}-----| %{eoc}room %d", rooms[i].id);
		ft_printf("%{yellow} |-----%{eoc}\n");
		ft_printf("   name : %s\n", tab_hash[rooms[i].id]);
		name_color(rooms[i].color);
		ft_printf("   coord: (x = %d, ", rooms[i].coord.x);
		ft_printf("y = %d)\n", rooms[i].coord.y);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

static void		print_val_green(int **matrix, int i, int j)
{
	if (matrix[i][j])
		ft_printf("%{GREEN}%-3d%{eoc}", 1);
	else
		ft_printf("%-3d", 0);
}

static void		print_adj_matrix(int **matrix, int size)
{
	int			i;
	int			j;

	ft_printf(" %{CYAN}Adjacency Matrix:%{eoc}\n\n");
	i = -1;
	ft_putstr("       | ");
	while (++i < size)
		ft_printf("%-3d", i);
	i = -1;
	ft_putstr("\n    ----");
	while (++i < size)
		ft_putstr("---");
	ft_putchar('\n');
	i = -1;
	while (++i < size)
	{
		j = -1;
		ft_printf("%6d | ", i);
		while (++j < size)
			print_val_green(matrix, i, j);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

static void		print_infos_tabhash(char **tab_hash, int size)
{
	int			i;

	i = 0;
	ft_printf("%{CYAN} Hash Table:%{eoc}\n");
	ft_printf("  ___________\n");
	ft_printf("   id | name\n");
	ft_printf("  -----------\n");
	while (i < size)
	{
		ft_printf("%5d | %s\n", i, tab_hash[i]);
		i++;
	}
	ft_putchar('\n');
}

void			print_debug(t_infos *infos)
{
	ft_printf("%{blue}==================%{BLUE} DEGUB MODE ");
	ft_printf("%{blue}==================%{eoc}\n");
	print_infos_tabhash(infos->tab_hash, infos->v);
	ft_printf(" We have %{RED}%d%{eoc} ant.\n", infos->ants);
	ft_printf(" The Graph have %{GREEN}%d%{eoc} vertex.\n", infos->v);
	ft_printf(" start: [%{RED}%s%{eoc}] | ", infos->tab_hash[infos->start]);
	ft_printf(" end: [%{RED}%s%{eoc}]\n", infos->tab_hash[infos->end]);
	print_infos_rooms(infos->tab_hash, infos->rooms, infos->v);
	print_adj_matrix(infos->links, infos->v);
	print_life_ants(infos);
	ft_printf(" Done in %{RED}%d%{eoc} instruction(s)\n", infos->shots);
	ft_printf("%{blue}========================");
	ft_printf("========================%{eoc}\n\n");
}
