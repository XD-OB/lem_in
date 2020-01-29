/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 01:41:34 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/29 06:47:24 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displayer.h"

int				main(int ac, char **av)
{
	t_display	display;

	if (!store_data(ac, av, &(display.infos)))
		return (EXIT_FAILURE);
	if (!init_display(&display))
		return (EXIT_FAILURE);
	print_usage();
	Mix_PlayMusic(display.env.music, display.mute);
	displayer_loop(&display);
	free_display(&display);
	return (EXIT_SUCCESS);
}
