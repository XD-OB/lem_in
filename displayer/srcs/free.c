/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 02:15:59 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/24 02:16:18 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

void			free_error(t_infos *infos)
{
	free_infos(infos);
	ft_putstr("ERROR\n");
	exit(1);
}

void			free_infos(t_infos *infos)
{
	int			i;

	if (infos->input)
		chr_free(&(infos->input));
	if (infos->tab_hash)
		hash_freetab(&infos->tab_hash, infos->v);
	if (infos->rooms)
		free(infos->rooms);
	if (infos->links)
		mxint_free(&(infos->links), infos->v);
	if (infos->tab_ants)
	{
		i = -1;
		while (++i < infos->ants)
			free(infos->tab_ants[i].tab_life);
		free(infos->tab_ants);
	}
}

void			free_display(t_display *display)
{
	TTF_CloseFont(display->font_text);
	free_infos(&(display->infos));
	sdl_close(&(display->env));
}
